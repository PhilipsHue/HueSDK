/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSBridgeBackupErrorCode) {
    PHSBridgeBackupErrorCodeUnknown = -1,
    PHSBridgeBackupErrorCodeNone    = 0,
    PHSBridgeBackupErrorCodeExportFailed,
    PHSBridgeBackupErrorCodeImportFailed
};
