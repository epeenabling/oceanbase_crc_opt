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

#include "ob_mock_tx_log_adapter.h"
#include "storage/tx/ob_tx_ls_log_writer.h"
#include "storage/tx/ob_trans_ctx_mgr.h"
#include <gtest/gtest.h>

namespace oceanbase {

using namespace transaction;
using namespace storage;
using namespace share;


namespace unittest {
MockTxLogAdapter tx_log_adapter;
MockTxLogParam param;
ObTxLSLogWriter ls_log_writer;

class TestLSLogWriter : public ::testing::Test {
public:
  virtual void SetUp()
  {
    tx_log_adapter.init(&param);
    tx_log_adapter.start();
  }
  virtual void TearDown()
  {
    tx_log_adapter.stop();
    tx_log_adapter.wait();
    tx_log_adapter.destroy();
  }

public:
};

const ObLSID TEST_LS_ID(735);

TEST_F(TestLSLogWriter, submit_start_working_log)
{
  int64_t tmp_tenant_id = 1004;
  ObLSTxCtxMgr tmp_mgr;
  common::ObConcurrentFIFOAllocator tmp_allocator;
  
  ObTxLogBlock replay_block;
  int64_t replay_hint = 0;
  int64_t log_ts = 0;
  std::string log_string;
  ObTxLogHeader log_header;
  ObTxStartWorkingLogTempRef tmp_ref;
  ObTxStartWorkingLog sw_log(tmp_ref);
  int64_t test_leader_epoch  = 1308;

  ObTxLogBlockHeader block_header;
  
  ASSERT_EQ(OB_SUCCESS, ls_log_writer.init(TEST_LS_ID, &tx_log_adapter, (ObLSTxCtxMgr *)&tmp_mgr));
  ASSERT_EQ(OB_SUCCESS, ls_log_writer.submit_start_working_log(test_leader_epoch,log_ts));
  
  ASSERT_EQ(true, tx_log_adapter.get_log(log_ts, log_string));
  ASSERT_EQ(OB_SUCCESS,
            replay_block.init_with_header(log_string.c_str(), log_string.size(), replay_hint, block_header));
  ASSERT_EQ(OB_SUCCESS, replay_block.get_next_log(log_header));
  EXPECT_EQ(ObTxLogType::TX_START_WORKING_LOG, log_header.get_tx_log_type());
  ASSERT_EQ(OB_SUCCESS, replay_block.deserialize_log_body(sw_log));
  EXPECT_EQ(test_leader_epoch, sw_log.get_leader_epoch());
}

} // namespace unittest
} // namespace oceanbase

using namespace oceanbase;

int main(int argc, char **argv)
{
  int ret = 1;
  ObLogger &logger = ObLogger::get_logger();
  logger.set_file_name("test_ls_log_writer.log", true);
  logger.set_log_level(OB_LOG_LEVEL_INFO);
  testing::InitGoogleTest(&argc, argv);
  ret = RUN_ALL_TESTS();
  return ret;
}
