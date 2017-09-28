/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSDeviceSoftwareUpdateState) {
    PHSDeviceSoftwareUpdateStateNotSet         = -1,
    PHSDeviceSoftwareUpdateStateUnknown        = 0,
    PHSDeviceSoftwareUpdateStateNotUpdatable   = 1,
    PHSDeviceSoftwareUpdateStateNoUpdates      = 2,
    PHSDeviceSoftwareUpdateStateTransferring   = 3,
    PHSDeviceSoftwareUpdateStateReadyToInstall = 4,
    PHSDeviceSoftwareUpdateStateInstalling     = 5,
    PHSDeviceSoftwareUpdateStateBatteryLow     = 6,
    PHSDeviceSoftwareUpdateStateImageRejected  = 7,
    PHSDeviceSoftwareUpdateStateError          = 8
};
