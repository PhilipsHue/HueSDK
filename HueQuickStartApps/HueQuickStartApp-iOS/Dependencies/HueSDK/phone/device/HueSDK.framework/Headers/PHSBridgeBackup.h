/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"
#import "PHSBridgeBackupStatus.h"
#import "PHSBridgeBackupErrorCode.h"

@interface PHSBridgeBackup : PHSDomainObject

/**
 The current status code of the backup
 */
@property (assign, nonatomic) PHSBridgeBackupStatus status;

/**
 The error code
 */
@property (assign, nonatomic, readonly) PHSBridgeBackupErrorCode errorCode;

@end
