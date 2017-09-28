/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSBridgeBackupStatus) {
    PHSBridgeBackupStatusUnknown = -1,
    PHSBridgeBackupStatusNone    = 0,
    PHSBridgeBackupStatusIdle,
    PHSBridgeBackupStatusStartMigration,
    PHSBridgeBackupStatusFilereadyDisabled,
    PHSBridgeBackupStatusPrepareRestore,
    PHSBridgeBackupStatusRestoring,
};
