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

#ifndef OCEANBASE_TRANSACTION_OB_I_TS_SOURCE_
#define OCEANBASE_TRANSACTION_OB_I_TS_SOURCE_

#include <stdint.h>
#include "lib/utility/ob_print_utils.h"
#include "ob_trans_define.h"

namespace oceanbase
{
namespace transaction
{
class ObTsCbTask;

enum
{
  TS_SOURCE_UNKNOWN = -1,
  TS_SOURCE_GTS = 0,
  MAX_TS_SOURCE,
};

OB_INLINE bool is_valid_ts_source(const int ts_type)
{
  return TS_SOURCE_UNKNOWN < ts_type && ts_type < MAX_TS_SOURCE;
}

inline bool is_ts_type_external_consistent(const int64_t ts_type)
{
  return ts_type == TS_SOURCE_GTS;
}

class ObTsParam
{
public:
  ObTsParam() { reset(); }
  ~ObTsParam() { destroy(); }
  void reset() { need_inc_ = true; }
  void destroy() { reset(); }
  void set_need_inc(const bool need_inc) { need_inc_ = need_inc; }
  bool need_inc() const { return need_inc_; }
private:
  // gts值是否需要+1，在gts cache管理中是默认加一的
  bool need_inc_;
};

class ObITsSource
{
public:
  virtual int update_gts(const int64_t gts, bool &update) = 0;
  virtual int get_gts(const MonotonicTs stc, ObTsCbTask *task, int64_t &gts, MonotonicTs &receive_gts_ts) = 0;
  virtual int get_gts(ObTsCbTask *task, int64_t &gts) = 0;
  virtual int wait_gts_elapse(const int64_t gts, ObTsCbTask *task, bool &need_wait) = 0;
  virtual int wait_gts_elapse(const int64_t gts) = 0;
  virtual int refresh_gts(const bool need_refresh) = 0;
  virtual int update_base_ts(const int64_t base_ts) = 0;
  virtual int get_base_ts(int64_t &base_ts) = 0;
  virtual bool is_external_consistent() = 0;
public:
  VIRTUAL_TO_STRING_KV("", "");
};

}
}//end of namespace oceanbase

#endif //OCEANBASE_TRANSACTION_OB_I_TS_SOURCE_
