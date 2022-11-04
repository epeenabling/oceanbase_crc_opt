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

#ifndef OCEANBASE_STORAGE_TABLET_OB_TABLET_META
#define OCEANBASE_STORAGE_TABLET_OB_TABLET_META

#include "common/ob_tablet_id.h"
#include "lib/allocator/ob_allocator.h"
#include "lib/allocator/page_arena.h"
#include "lib/container/ob_fixed_array.h"
#include "lib/container/ob_se_array.h"
#include "lib/utility/ob_print_utils.h"
#include "lib/utility/ob_template_utils.h"
#include "lib/utility/ob_unify_serialize.h"
#include "share/ob_tablet_autoincrement_param.h"
#include "storage/ob_storage_schema.h"
#include "storage/ob_storage_struct.h"
#include "storage/blocksstable/ob_sstable.h"
#include "storage/compaction/ob_medium_compaction_mgr.h"
#include "storage/ddl/ob_tablet_barrier_log.h"
#include "storage/tablet/ob_tablet_binding_helper.h"
#include "storage/tablet/ob_tablet_multi_source_data.h"
#include "storage/tx/ob_trans_define.h"
#include "storage/high_availability/ob_tablet_ha_status.h"
#include "storage/tablet/ob_tablet_table_store_flag.h"

namespace oceanbase
{
namespace storage
{
struct ObMigrationTabletParam;

class ObTabletMeta final
{
public:
  static const int64_t INIT_CLOG_CHECKPOINT_TS;

public:
  ObTabletMeta();
  ObTabletMeta(const ObTabletMeta &other) = delete;
  ObTabletMeta &operator=(const ObTabletMeta &other) = delete;
  ~ObTabletMeta();
public:
  int init(
      common::ObIAllocator &allocator,
      const share::ObLSID &ls_id,
      const common::ObTabletID &tablet_id,
      const common::ObTabletID &data_tablet_id,
      const common::ObTabletID &lob_meta_tablet_id,
      const common::ObTabletID &lob_piece_tablet_id,
      const int64_t create_scn,
      const int64_t snapshot_version,
      const lib::Worker::CompatMode compat_mode,
      const ObTabletTableStoreFlag &table_store_flag,
      const int64_t max_sync_storage_schema_version);
  int init(
      common::ObIAllocator &allocator,
      const ObTabletMeta &old_tablet_meta,
      const int64_t snapshot_version,
      const int64_t multi_version_start,
      const ObTabletTxMultiSourceDataUnit &tx_data,
      const ObTabletBindingInfo &ddl_data,
      const share::ObTabletAutoincSeq &autoinc_seq,
      const int64_t max_sync_storage_schema_version,
      const int64_t clog_checkpoint_ts = 0,
      const int64_t ddl_checkpoint_ts = 0,
      const int64_t ddl_start_log_ts = 0,
      const int64_t ddl_snapshot_version = 0);
  int init(
      common::ObIAllocator &allocator,
      const ObMigrationTabletParam &param);
  int init(
      common::ObIAllocator &allocator,
      const ObTabletMeta &old_tablet_meta,
      const ObTabletTxMultiSourceDataUnit &tx_data,
      const ObTabletBindingInfo &ddl_data,
      const share::ObTabletAutoincSeq &autoinc_seq,
      const ObMigrationTabletParam *tablet_meta);

  void reset();
  bool is_valid() const;

  // serialize & deserialize
  int serialize(char *buf, const int64_t len, int64_t &pos);
  int deserialize(
      common::ObIAllocator &allocator,
      const char *buf,
      const int64_t len,
      int64_t &pos);
  int64_t get_serialize_size() const;

  int update(const ObMigrationTabletParam &param);
  int update_create_scn(const int64_t create_scn);
public:
  static int deserialize_id(
      const char *buf,
      const int64_t len,
      int64_t &pos,
      share::ObLSID &ls_id,
      common::ObTabletID &tablet_id);
  static int init_report_info(
      const blocksstable::ObSSTable *sstable,
      const int64_t report_version,
      ObTabletReportStatus &report_status);
public:
  TO_STRING_KV(K_(version),
               K_(ls_id),
               K_(tablet_id),
               K_(data_tablet_id),
               K_(ref_tablet_id),
               K_(create_scn),
               K_(start_scn),
               K_(clog_checkpoint_ts),
               K_(ddl_checkpoint_ts),
               K_(snapshot_version),
               K_(multi_version_start),
               K_(autoinc_seq),
               K_(compat_mode),
               K_(ha_status),
               K_(report_status),
               K_(tx_data),
               K_(ddl_data),
               K_(table_store_flag),
               K_(ddl_start_log_ts),
               K_(ddl_snapshot_version),
               K_(max_sync_storage_schema_version));

public:
  int32_t version_;
  int32_t length_;
  share::ObLSID ls_id_;
  common::ObTabletID tablet_id_;
  common::ObTabletID data_tablet_id_;
  common::ObTabletID ref_tablet_id_;
  bool has_next_tablet_;
  int64_t create_scn_;
  int64_t start_scn_;
  int64_t clog_checkpoint_ts_; // may less than last_minor->end_log_ts
  int64_t ddl_checkpoint_ts_;
  // snapshot_version of last minor
  int64_t snapshot_version_;
  int64_t multi_version_start_;
  lib::Worker::CompatMode compat_mode_;
  share::ObTabletAutoincSeq autoinc_seq_;
  ObTabletHAStatus ha_status_;
  ObTabletReportStatus report_status_;
  ObTabletTxMultiSourceDataUnit tx_data_;
  ObTabletBindingInfo ddl_data_;
  ObTabletTableStoreFlag table_store_flag_;
  int64_t ddl_start_log_ts_;
  int64_t ddl_snapshot_version_;
  int64_t max_sync_storage_schema_version_;
  //ATTENTION : Add a new variable need consider ObMigrationTabletParam
  // and tablet meta init interface for migration.
  // yuque : https://yuque.antfin.com/ob/ob-backup/zzwpuh

private:
  int inner_check_(
      const ObTabletMeta &old_tablet_meta,
      const ObMigrationTabletParam *tablet_meta);
private:
  static const int32_t TABLET_META_VERSION = 1;
private:
  bool is_inited_;
};

// decouple tablet meta from migration parameter
struct ObMigrationTabletParam final
{
public:
  ObMigrationTabletParam();
  ~ObMigrationTabletParam() = default;
  ObMigrationTabletParam(const ObMigrationTabletParam &) = delete;
  ObMigrationTabletParam &operator=(const ObMigrationTabletParam &) = delete;
public:
  bool is_valid() const;
  int serialize(char *buf, const int64_t len, int64_t &pos) const;
  int deserialize(const char *buf, const int64_t len, int64_t &pos);
  int64_t get_serialize_size() const;
  void reset();
  int assign(const ObMigrationTabletParam &param);

  // used for restore PENDING tablet, the placeholder tablet doesn't have storage schema to use
  static int construct_placeholder_storage_schema(
      ObIAllocator &allocator,
      ObStorageSchema &storage_schema);

  TO_STRING_KV(K_(ls_id),
               K_(tablet_id),
               K_(data_tablet_id),
               K_(ref_tablet_id),
               K_(create_scn),
               K_(start_scn),
               K_(clog_checkpoint_ts),
               K_(ddl_checkpoint_ts),
               K_(snapshot_version),
               K_(multi_version_start),
               K_(autoinc_seq),
               K_(compat_mode),
               K_(ha_status),
               K_(report_status),
               K_(tx_data),
               K_(ddl_data),
               K_(storage_schema),
               K_(medium_info_list),
               K_(table_store_flag),
               K_(max_sync_storage_schema_version));
public:

  common::ObArenaAllocator allocator_; // for storage schema
  share::ObLSID ls_id_;
  common::ObTabletID tablet_id_;
  common::ObTabletID data_tablet_id_;
  common::ObTabletID ref_tablet_id_;
  int64_t create_scn_;
  int64_t start_scn_;              // for migration
  int64_t clog_checkpoint_ts_;
  int64_t ddl_checkpoint_ts_;
  int64_t snapshot_version_;
  int64_t multi_version_start_;
  lib::Worker::CompatMode compat_mode_;
  share::ObTabletAutoincSeq autoinc_seq_;
  ObTabletHAStatus ha_status_;
  ObTabletReportStatus report_status_;
  ObTabletTxMultiSourceDataUnit tx_data_;
  ObTabletBindingInfo ddl_data_;
  ObStorageSchema storage_schema_;
  compaction::ObMediumCompactionInfoList medium_info_list_;
  ObTabletTableStoreFlag table_store_flag_;
  int64_t ddl_start_log_ts_;
  int64_t ddl_snapshot_version_;
  // max_sync_version may less than storage_schema.schema_version_ when major update schema
  int64_t max_sync_storage_schema_version_; 
};

} // namespace storage
} // namespace oceanbase

#endif // OCEANBASE_STORAGE_TABLET_OB_TABLET_META
