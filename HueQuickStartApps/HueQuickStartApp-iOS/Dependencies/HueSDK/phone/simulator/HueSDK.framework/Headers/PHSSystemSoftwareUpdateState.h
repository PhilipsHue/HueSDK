/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSSystemSoftwareUpdateState) {
    PHSSystemSoftwareUpdateStateNotSet            = -1,
    PHSSystemSoftwareUpdateStateUnknown           = 0,
    PHSSystemSoftwareUpdateStateNoUpdates         = 1,
    PHSSystemSoftwareUpdateStateTransferring      = 2,
    PHSSystemSoftwareUpdateStateAnyReadyToInstall = 3,
    PHSSystemSoftwareUpdateStateAllReadyToInstall = 4,
    PHSSystemSoftwareUpdateStateInstalling        = 5,
};

