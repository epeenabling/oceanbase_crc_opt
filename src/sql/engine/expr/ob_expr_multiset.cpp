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

#define USING_LOG_PREFIX SQL_ENG
#include "sql/engine/expr/ob_expr_multiset.h"
#include "sql/engine/ob_physical_plan_ctx.h"
#include "sql/engine/ob_exec_context.h"
#include "lib/hash/ob_hashmap.h"
#include "pl/ob_pl_user_type.h"
#include "pl/ob_pl_allocator.h"
#include "lib/utility/utility.h"

namespace oceanbase
{
using namespace common;
namespace sql
{
OB_SERIALIZE_MEMBER((ObExprMultiSet, ObExprOperator),
                    ms_type_,
                    ms_modifier_);

typedef hash::ObHashMap<ObObj, int64_t, common::hash::NoPthreadDefendMode> LocalNTSHashMap;

ObExprMultiSet::ObExprMultiSet(ObIAllocator &alloc)
  : ObExprOperator(alloc, T_OP_MULTISET, N_MULTISET, 2, NOT_ROW_DIMENSION),
    ms_type_(ObMultiSetType::MULTISET_TYPE_INVALID),
    ms_modifier_(ObMultiSetModifier::MULTISET_MODIFIER_INVALID)
{
}

ObExprMultiSet::~ObExprMultiSet()
{
}

void ObExprMultiSet::reset()
{
  ms_type_ = ObMultiSetType::MULTISET_TYPE_INVALID;
  ms_modifier_ = ObMultiSetModifier::MULTISET_MODIFIER_INVALID;
  ObExprOperator::reset();
}

int ObExprMultiSet::assign(const ObExprOperator &other)
{
  int ret = OB_SUCCESS;
  if (other.get_type() != T_OP_MULTISET) {
    ret = OB_ERR_UNEXPECTED;
    LOG_WARN("expr operator is mismatch", K(other.get_type()));
  } else if (OB_FAIL(ObExprOperator::assign(other))) {
    LOG_WARN("assign parent expr failed", K(ret));
  } else {
    const ObExprMultiSet &other_expr = static_cast<const ObExprMultiSet &>(other);
    ms_type_ = other_expr.ms_type_;
    ms_modifier_ = other_expr.ms_modifier_;
  }
  return ret;
}

int ObExprMultiSet::calc_result_type2(ObExprResType &type,
                                    ObExprResType &type1,
                                    ObExprResType &type2,
                                    ObExprTypeCtx &type_ctx) const
{
  UNUSED(type_ctx);
  int ret = OB_SUCCESS;
  if (lib::is_oracle_mode()) {
    if (type1.is_ext() && type2.is_ext()) {
      type.set_ext();
      type.set_precision(DEFAULT_PRECISION_FOR_BOOL);
      type.set_scale(DEFAULT_SCALE_FOR_INTEGER);
      type.set_calc_type(type1.get_calc_type());
      type.set_result_flag(NOT_NULL_FLAG);
    } else {
      ret = OB_ERR_UNEXPECTED;
      LOG_WARN("multiset operator not support non udt type", K(type1), K(type2), K(ret));
    }
  } else {
    ret = OB_NOT_SUPPORTED;
    LOG_USER_ERROR(OB_NOT_SUPPORTED, "this function in MySql mode");
    LOG_WARN("multiset operator not support non udt type", K(type1), K(type2), K(ret));
  }

  return ret;
}

  #define FILL_ELEM(ca, dst, offset) \
  do { \
    const ObObj *elem = NULL; \
    int64_t i = 0; \
    int64_t cnt = 0; \
    for (; OB_SUCC(ret) && i < ca->get_count(); ++i) { \
      bool is_del = false; \
      if (OB_FAIL(ca->is_elem_deleted(i, is_del))) { \
        LOG_WARN("failed to test collection elem is deleted", K(ret)); \
      } else if (!is_del) { \
        CK (cnt < ca->get_actual_count()); \
        if (OB_SUCC(ret)) { \
          elem = static_cast<ObObj *>(ca->get_data()) + i; \
          if (OB_NOT_NULL(elem)) { \
            if (OB_FAIL(deep_copy_obj(*coll_allocator, *elem, dst[cnt + offset]))) { \
              LOG_WARN("fail to fill obobj", K(*elem), K(ret)); \
            } else { \
              cnt++; \
            } \
          } else { \
            ret = OB_ERR_UNEXPECTED; \
            LOG_WARN("get null collection element", K(ret), K(i)); \
          } \
        } else { \
          ret = OB_ERR_UNEXPECTED; \
          LOG_WARN("collection element count illegal", K(ret)); \
        } \
      } \
    } \
  } while(0)

  #define FILL_ELEM_DISTICT(ca, d_map, allow_dup) \
  do { \
    const ObObj *elem = NULL; \
    int64_t i = 0; \
    for (; OB_SUCC(ret) && i < ca->get_count(); ++i) { \
      bool is_del = false; \
      if (OB_FAIL(ca->is_elem_deleted(i, is_del))) { \
        LOG_WARN("failed to test collection elem is deleted", K(ret)); \
      } else if (!is_del) { \
        elem = static_cast<ObObj *>(ca->get_data()) + i; \
        ret = d_map.set_refactored(*elem, 1); \
        if (OB_HASH_EXIST == ret) { \
          if (allow_dup) { \
            int64_t *dup_cnt = const_cast<int64_t *>(d_map.get(*elem)); \
            if (OB_NOT_NULL(dup_cnt)) { \
              *dup_cnt = *dup_cnt + 1; \
              ret = OB_SUCCESS; \
            } else { \
              ret = OB_ERR_UNEXPECTED; \
              LOG_WARN("get hash map value failed", K(ret), K(*elem)); \
            } \
          } else { \
            ret = OB_SUCCESS; \
          } \
        } else if (OB_FAIL(ret)) { \
          LOG_WARN("insert elem into hashmap failed.", K(ret)); \
        } \
      } \
    }\
  } while(0)

int ObExprMultiSet::calc_ms_intersect(common::ObIAllocator *coll_allocator,
                                      pl::ObPLCollection *c1,
                                      pl::ObPLCollection *c2,
                                      ObObj *&data_arr,
                                      int64_t &elem_count,
                                      ObMultiSetType ms_type,
                                      ObMultiSetModifier ms_modifier)
{
  return calc_ms_impl(coll_allocator, c1, c2, data_arr, elem_count, ms_type, ms_modifier);
}

int ObExprMultiSet::calc_ms_except(common::ObIAllocator *coll_allocator,
                                   pl::ObPLCollection *c1,
                                   pl::ObPLCollection *c2,
                                   ObObj *&data_arr,
                                   int64_t &elem_count,
                                   ObMultiSetType ms_type,
                                   ObMultiSetModifier ms_modifier)
{
  return calc_ms_impl(coll_allocator, c1, c2, data_arr, elem_count, ms_type, ms_modifier);
}

int ObExprMultiSet::calc_ms_impl(common::ObIAllocator *coll_allocator,
                                   pl::ObPLCollection *c1,
                                   pl::ObPLCollection *c2,
                                   ObObj *&data_arr,
                                   int64_t &elem_count,
                                   ObMultiSetType ms_type,
                                   ObMultiSetModifier ms_modifier)
{
  int ret = OB_SUCCESS;
  if (MULTISET_MODIFIER_ALL == ms_modifier) {
    if (OB_FAIL(calc_ms_all_impl(coll_allocator, c1, c2, data_arr,
                                 elem_count, true, ms_type, ms_modifier))) {
      LOG_WARN("failed to calc except all", K(ret));
    }
  } else if (MULTISET_MODIFIER_DISTINCT == ms_modifier) {
    if (OB_FAIL(calc_ms_distinct_impl(coll_allocator, c1, c2, data_arr,
                                      elem_count, ms_type, ms_modifier))) {
      LOG_WARN("failed to calc except distinct", K(ret));
    }
  } else {
    ret = OB_ERR_UNEXPECTED;
    LOG_WARN("unexpected multiest except modifier", K(ms_modifier), K(ms_type));
  }
  return ret;
}

int ObExprMultiSet::calc_ms_one_distinct(common::ObIAllocator *coll_allocator,
                                   ObObj *objs,
                                   int64_t count,
                                   ObObj *&data_arr,
                                   int64_t &elem_count)
{
  int ret = OB_SUCCESS;
  LocalNTSHashMap dmap_c;
  int res_cnt = 0;
  if (0 == count) {
    // do nothing
  } else if (OB_ISNULL(objs)) {
    ret = OB_ERR_UNEXPECTED;
    LOG_WARN("objs array is null", K(count));
  } else {
    if (OB_FAIL(dmap_c.create(count, ObModIds::OB_SQL_HASH_SET))) {
      LOG_WARN("fail create hash map", K(count), K(ret));
    } else {
      const ObObj *elem = NULL;
      for (int64_t i = 0; OB_SUCC(ret) && i < count; ++i) {
        elem = objs + i;
        ret = dmap_c.set_refactored(*elem, i);
        if (OB_HASH_EXIST == ret) {
          ret = OB_SUCCESS;
          continue;
        } else if (OB_SUCC(ret)) {
          if (i != res_cnt) {
            objs[res_cnt] = *elem;
          }
          res_cnt++;
        } else {
          LOG_WARN("insert elem into hashmap failed.", K(ret));
        }
      }
    }
    CK (res_cnt > 0);
    if (OB_SUCC(ret)) {
      // 计算结果大于100，且有效数据是超过50%，拷贝有效数据到新的内存，释放老内存
      // 这两个数字是拍脑袋想出来的，主要目的是希望节省内存。
      if ((res_cnt < count / 2) && (count > 100)) {
        data_arr = static_cast<ObObj *>(coll_allocator->alloc(res_cnt * sizeof(ObObj)));
        if (OB_ISNULL(data_arr)) {
          ret = OB_ALLOCATE_MEMORY_FAILED;
          LOG_WARN("allocate result obobj array failed, size is: ", K(res_cnt));
        } else {
          for (int64_t i = 0; i < res_cnt; ++i) {
            if (OB_FAIL(deep_copy_obj(*coll_allocator, objs[i], data_arr[i]))) {
              LOG_WARN("copy obobj failed.", K(ret));
            }
          }
        }
        elem_count = res_cnt;
      } else {
        data_arr = objs;
        elem_count = res_cnt;
      }
    }
  }
  return ret;
}

int ObExprMultiSet::calc_ms_distinct_impl(common::ObIAllocator *coll_allocator,
                                   pl::ObPLCollection *c1,
                                   pl::ObPLCollection *c2,
                                   ObObj *&data_arr,
                                   int64_t &elem_count,
                                   ObMultiSetType ms_type,
                                   ObMultiSetModifier ms_modifier)
{
  int ret = OB_SUCCESS;
  ObObj *tmp_res = NULL;
  if (OB_FAIL(calc_ms_all_impl(coll_allocator, c1, c2, tmp_res,
                               elem_count, false, ms_type, ms_modifier))) {
    LOG_WARN("calc intersect or except failed.", K(ret));
  } else if (OB_FAIL(calc_ms_one_distinct(coll_allocator,
                                          tmp_res,
                                          elem_count,
                                          data_arr,
                                          elem_count))) {
    LOG_WARN("calc distinct failed.", K(ret));
  } else {
    if (OB_NOT_NULL(tmp_res) && OB_NOT_NULL(data_arr) && tmp_res != data_arr) {
      coll_allocator->free(tmp_res);
      tmp_res = NULL;
    }
  }
  return ret;
}

int ObExprMultiSet::calc_ms_all_impl(common::ObIAllocator *coll_allocator,
                                   pl::ObPLCollection *c1,
                                   pl::ObPLCollection *c2,
                                   ObObj *&data_arr,
                                   int64_t &elem_count,
                                   bool allow_dup,
                                   ObMultiSetType ms_type,
                                   ObMultiSetModifier ms_modifier)
{
  UNUSED(ms_modifier);
  int ret = OB_SUCCESS;
  int64_t cnt1 = c1->get_actual_count();
  int64_t i = 0, index = 0;
  LocalNTSHashMap dmap_c2;
  if (0 == cnt1) {
    elem_count = 0;
  } else if ( 0 == c2->get_actual_count()) {
    if (MULTISET_TYPE_INTERSECT == ms_type) {
      elem_count = 0;
    } else if (MULTISET_TYPE_EXCEPT == ms_type) {
      data_arr =
       static_cast<ObObj *>(coll_allocator->alloc(c1->get_actual_count() * sizeof(ObObj)));
      FILL_ELEM(c1, data_arr, 0);
      OX (elem_count = c1->get_actual_count());
    }
  } else {
    if (OB_FAIL(dmap_c2.create(c2->get_actual_count(), ObModIds::OB_SQL_HASH_SET))) {
      LOG_WARN("fail create hash map", K(c2->get_actual_count()), K(ret));
    } else {
      FILL_ELEM_DISTICT(c2, dmap_c2, allow_dup);
    }
    if (OB_SUCC(ret)) {
      const ObObj *elem = NULL;
      data_arr =
       static_cast<ObObj *>(coll_allocator->alloc(c1->get_actual_count() * sizeof(ObObj)));
      if (OB_ISNULL(data_arr)) {
        ret = OB_ALLOCATE_MEMORY_FAILED;
        LOG_WARN("cann't alloc memory", K(c1->get_actual_count()), K(c1->get_count()));
      } else {
        int64_t *dup_cnt = NULL;
        bool is_del = false;
        for (i = 0; OB_SUCC(ret) && i < c1->get_count(); ++i) {
          if (OB_FAIL(c1->is_elem_deleted(i, is_del))) {
            LOG_WARN("failed to check collection elem deleted", K(ret));
          } else if (!is_del) {
            elem = static_cast<ObObj *>(c1->get_data()) + i;
        #define COPY_ELEM(iscopy) \
        do{ \
          if (iscopy) { \
            OZ (common::deep_copy_obj(*coll_allocator, *elem, data_arr[index])); \
            ++index; \
          }\
        } while(0)

        /* The except ALL keyword instructs Oracle to return all elements in nested_table1 that are
          not in nested_table2. For example, if a particular element occurs m times in
          nested_table1 and n times in nested_table2, then the result will have (m-n)
          occurrences of the element if m >n and 0 occurrences if m<=n.
        */
        /* The intersect ALL keyword instructs Oracle to return all common occurrences of elements
          that are in the two input nested tables, including duplicate common values and
          duplicate common NULL occurrences. For example, if a particular value occurs m
          times in nested_table1 and n times in nested_table2, then the result would
          contain the element min(m,n) times.
        */
            if (allow_dup) {
              dup_cnt = const_cast<int64_t *>(dmap_c2.get(*elem));
              if (MULTISET_TYPE_EXCEPT == ms_type) {
                if (OB_ISNULL(dup_cnt)) {
                  COPY_ELEM(true);
                } else {
                  if (OB_UNLIKELY(0 > *dup_cnt)) {
                    ret = OB_ERR_UNEXPECTED;
                    LOG_WARN("unexpected collection elem count in hash map", K(ret), K(*dup_cnt));
                  } else if (0 != *dup_cnt) {
                    *dup_cnt -= 1;
                  } else {
                    COPY_ELEM(true);
                  }
                }
              } else {
                if (OB_ISNULL(dup_cnt)) {
                  // do nothing
                } else {
                  if (OB_UNLIKELY(0 > *dup_cnt)) {
                    ret = OB_ERR_UNEXPECTED;
                    LOG_WARN("unexpected collection elem count in hash map", K(ret), K(*dup_cnt));
                  } else if (0 != *dup_cnt) {
                    COPY_ELEM(true);
                    *dup_cnt -= 1;
                  } else {
                  }
                }
              }
            } else {
              if (OB_ISNULL(dmap_c2.get(*elem))) {
                COPY_ELEM(MULTISET_TYPE_EXCEPT == ms_type);
              } else {
                COPY_ELEM(MULTISET_TYPE_INTERSECT == ms_type);
              }
            }
          }
        }
        elem_count = index;
      }
    }
  }
  return ret;
}

int ObExprMultiSet::calc_ms_union(common::ObIAllocator *coll_allocator,
                                  pl::ObPLCollection *c1,
                                  pl::ObPLCollection *c2,
                                  ObObj *&data_arr,
                                  int64_t &elem_count,
                                  ObMultiSetType ms_type,
                                  ObMultiSetModifier ms_modifier)
{
  int ret = OB_SUCCESS;
  int64_t count = c1->get_actual_count() + c2->get_actual_count();
  int64_t alloc_size = 0;
  LocalNTSHashMap distinct_map;
  if (0 == count) {
    elem_count = 0;
  } else {
    ObObj *tmp_res = NULL;
    alloc_size = count * sizeof(ObObj);
    tmp_res = static_cast<ObObj*>(coll_allocator->alloc(alloc_size));
    if (OB_ISNULL(tmp_res)) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
      LOG_WARN("failed to alloc memory", K(alloc_size));
    } else {
      FILL_ELEM(c1, tmp_res, 0);
      FILL_ELEM(c2, tmp_res, c1->get_actual_count());

      if (OB_SUCC(ret)) {
        if (MULTISET_MODIFIER_ALL == ms_modifier) {
          data_arr = tmp_res;
          elem_count = count;
        } else if (MULTISET_MODIFIER_DISTINCT == ms_modifier) {
          if (OB_FAIL(calc_ms_one_distinct(coll_allocator,
                                          tmp_res, count,
                                          data_arr, elem_count))) {
            LOG_WARN("calc multiset union distinc failed.", K(ret));
          } else {
            if (OB_NOT_NULL(tmp_res) && OB_NOT_NULL(data_arr) && data_arr != tmp_res) {
              coll_allocator->free(tmp_res);
            }
          }
        } else {
          ret = OB_ERR_UNEXPECTED;
          LOG_WARN("unexpected multiset modifier", K(ms_modifier), K(ms_type));
        }
      }
    }
  }
  return ret;
}
int ObExprMultiSet::cg_expr(ObExprCGCtx &expr_cg_ctx,
                            const ObRawExpr &raw_expr,
                            ObExpr &rt_expr) const
{
  int ret = OB_SUCCESS;
  if (2 != rt_expr.arg_cnt_) {
    ret = OB_ERR_UNEXPECTED;
    LOG_WARN("wrong param num for multi set", K(ret), K(rt_expr.arg_cnt_));
  } else {
    ObIAllocator &alloc = *expr_cg_ctx.allocator_;
    const ObMultiSetRawExpr &fun_sys = static_cast<const ObMultiSetRawExpr &>(raw_expr);
    ObExprMultiSetInfo *info = OB_NEWx(ObExprMultiSetInfo, (&alloc), alloc, T_OP_MULTISET);
    if (NULL == info) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
      LOG_WARN("allocate memory failed", K(ret));
    } else {
      OZ(info->from_raw_expr(fun_sys));
      rt_expr.extra_info_ = info;
    }
    rt_expr.eval_func_ = eval_multiset;
  }
  return ret;
}

int ObExprMultiSet::eval_multiset(const ObExpr &expr, ObEvalCtx &ctx, ObDatum &res)
{
  int ret = OB_SUCCESS;
  UNUSEDx(expr, ctx, res);
  ret = OB_NOT_SUPPORTED;
  LOG_WARN("not support udt", K(ret));
  return ret;
}

OB_DEF_SERIALIZE(ObExprMultiSetInfo)
{
  int ret = OB_SUCCESS;
  LST_DO_CODE(OB_UNIS_ENCODE,
              ms_type_,
              ms_modifier_);
  return ret;
}

OB_DEF_DESERIALIZE(ObExprMultiSetInfo)
{
  int ret = OB_SUCCESS;
  LST_DO_CODE(OB_UNIS_DECODE,
              ms_type_,
              ms_modifier_);
  return ret;
}

OB_DEF_SERIALIZE_SIZE(ObExprMultiSetInfo)
{
  int64_t len = 0;
  LST_DO_CODE(OB_UNIS_ADD_LEN,
              ms_type_,
              ms_modifier_);
  return len;
}

int ObExprMultiSetInfo::deep_copy(common::ObIAllocator &allocator,
                         const ObExprOperatorType type,
                         ObIExprExtraInfo *&copied_info) const
{
  int ret = common::OB_SUCCESS;
  OZ(ObExprExtraInfoFactory::alloc(allocator, type, copied_info));
  ObExprMultiSetInfo &other = *static_cast<ObExprMultiSetInfo *>(copied_info);
  other.ms_type_ = ms_type_;
  other.ms_modifier_ = ms_modifier_;
  return ret;
}

template <typename RE>
int ObExprMultiSetInfo::from_raw_expr(RE &raw_expr)
{
  int ret = OB_SUCCESS;
  ObMultiSetRawExpr &set_expr 
       = const_cast<ObMultiSetRawExpr &> (static_cast<const ObMultiSetRawExpr&>(raw_expr));
  ms_type_ = set_expr.get_multiset_type();
  ms_modifier_ = set_expr.get_multiset_modifier();
  return ret;
}

}  // namespace sql
}  // namespace oceanbase
