/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

// This file is for implementation of func json_merge_preserve
#define USING_LOG_PREFIX SQL_ENG
#include "ob_expr_json_merge_preserve.h"
#include "sql/engine/expr/ob_expr_json_func_helper.h"

using namespace oceanbase::common;
using namespace oceanbase::sql;

namespace oceanbase
{
namespace sql
{
ObExprJsonMergePreserve::ObExprJsonMergePreserve(ObIAllocator &alloc)
    : ObFuncExprOperator(alloc,
      T_FUN_SYS_JSON_MERGE_PRESERVE,
      N_JSON_MERGE_PRESERVE, 
      MORE_THAN_ONE,
      NOT_ROW_DIMENSION)
{
}

ObExprJsonMergePreserve::ObExprJsonMergePreserve(
    ObIAllocator &alloc,
    ObExprOperatorType type,
    const char *name,
    int32_t param_num, 
    int32_t dimension) : ObFuncExprOperator(alloc, type, name, param_num, dimension) 
{
  ;
}

ObExprJsonMergePreserve::~ObExprJsonMergePreserve()
{
}

int ObExprJsonMergePreserve::calc_result_typeN(ObExprResType& type,
                                        ObExprResType* types_stack,
                                        int64_t param_num,
                                        ObExprTypeCtx& type_ctx) const
{
  UNUSED(type_ctx);
  INIT_SUCC(ret);
  type.set_json();
  type.set_length((ObAccuracy::DDL_DEFAULT_ACCURACY[ObJsonType]).get_length());
  bool is_result_null = false;
  for (int64_t i = 0; OB_SUCC(ret) && !is_result_null && i < param_num; i++) {
    if (types_stack[0].get_type() == ObNullType) {
      is_result_null = true;
    } else if (OB_FAIL(ObJsonExprHelper::is_valid_for_json(types_stack, i, N_JSON_MERGE_PRESERVE))) {
      LOG_WARN("wrong type for json doc.", K(ret), K(types_stack[i].get_type()));
    }
  }
  return ret;
}

int ObExprJsonMergePreserve::calc_resultN(ObObj &result, const ObObj *objs, int64_t param_num, ObExprCtx &expr_ctx) const
{
  INIT_SUCC(ret);
  ObIAllocator *allocator = expr_ctx.calc_buf_;

  if (result_type_.get_collation_type() != CS_TYPE_UTF8MB4_BIN) {
    ret = OB_ERR_INVALID_JSON_CHARSET;
    LOG_WARN("invalid out put charset", K(ret), K(result_type_));
  } if (OB_ISNULL(allocator)) { // check allocator
    ret = OB_NOT_INIT;
    LOG_WARN("allcator not init", K(ret));
  } else {
    ObIJsonBase *j_base = NULL;
    ObIJsonBase *j_patch_node = NULL;
    bool has_null = false;
    for (int32 i = 0; OB_SUCC(ret) && i < param_num && !has_null; i++) {
      if (OB_FAIL(ObJsonExprHelper::get_json_doc(objs, allocator, i, j_patch_node, has_null))) {
        LOG_WARN("get_json_doc failed", K(ret));
      } else if (has_null) {
        // do nothing
      } else {
        if (i == 0) {
          j_base = j_patch_node;
        } else {
          ObIJsonBase *j_res = NULL;
          if (OB_FAIL(j_base->merge_tree(allocator, j_patch_node, j_res))) {
            LOG_WARN("error, merge tree failed", K(ret), K(i));
          } else {
            j_base = j_res;
          }
        }
      }
    }

    if (OB_SUCC(ret)) {
      ObString raw_bin;
      if (has_null) {
        result.set_null();
      } else if (OB_FAIL(j_base->get_raw_binary(raw_bin, allocator))) {
        LOG_WARN("fail to get json raw binary", K(ret));
      } else {
        result.set_collation_type(CS_TYPE_UTF8MB4_BIN);
        result.set_string(ObJsonType, raw_bin.ptr(), raw_bin.length());
      }
    }
  }

  return ret;
}

int ObExprJsonMergePreserve::eval_json_merge_preserve(const ObExpr &expr, ObEvalCtx &ctx, ObDatum &res)
{
  INIT_SUCC(ret);
  ObDatum *json_datum = NULL;
  common::ObArenaAllocator &temp_allocator = ctx.get_reset_tmp_alloc();
  ObIJsonBase *j_base = NULL;
  ObIJsonBase *j_patch_node = NULL;
  bool has_null = false;
  if (expr.datum_meta_.cs_type_ != CS_TYPE_UTF8MB4_BIN) {
    ret = OB_ERR_INVALID_JSON_CHARSET;
    LOG_WARN("invalid out put charset", K(ret), K(expr.datum_meta_.cs_type_));
  }

  for (int32 i = 0; OB_SUCC(ret) && i < expr.arg_cnt_ && !has_null; i++) {
    if (OB_FAIL(ObJsonExprHelper::get_json_doc(expr, ctx, temp_allocator, i, j_patch_node, has_null))) {
      LOG_WARN("get_json_doc failed", K(ret));
    } else if (has_null) {
      // do nothing
    } else {
      if (i == 0) {
        j_base = j_patch_node;
      } else {
        ObIJsonBase *j_res = NULL;
        if (OB_FAIL(j_base->merge_tree(&temp_allocator, j_patch_node, j_res))) {
          LOG_WARN("error, merge tree failed", K(ret), K(i));
        } else {
          j_base = j_res;
        }
      }
    }
  }

  if (OB_SUCC(ret)) {
    ObString raw_bin;
    if (has_null) {
      res.set_null();
    } else if (OB_FAIL(j_base->get_raw_binary(raw_bin, &temp_allocator))) {
      LOG_WARN("failed: get json raw binary", K(ret));
    } else {
      uint64_t length = raw_bin.length();
      char *buf = expr.get_str_res_mem(ctx, length);
      if (buf) {
        MEMCPY(buf, raw_bin.ptr(), length);
        res.set_string(buf, length);
      } else {
        ret = OB_ALLOCATE_MEMORY_FAILED;
        LOG_WARN("failed: allocate res string buffer.", K(ret), K(length));
      }
    }
  }

  return ret;
}

int ObExprJsonMergePreserve::cg_expr(ObExprCGCtx &expr_cg_ctx, const ObRawExpr &raw_expr,
                              ObExpr &rt_expr) const
{
  UNUSED(expr_cg_ctx);
  UNUSED(raw_expr);
  rt_expr.eval_func_ = eval_json_merge_preserve;
  return OB_SUCCESS;
}

}
}
