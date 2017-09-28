/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import "PHSDomainObject.h"
#import "PHSDeviceSoftwareUpdate.h"
#import "PHSSystemSoftwareUpdateState.h"
#import "PHSSystemSoftwareUpdateVersion.h"
#import "PHSSystemSoftwareUpdateAutoInstall.h"

@interface PHSSystemSoftwareUpdate : PHSDomainObject

@property (strong, nonatomic) PHSDeviceSoftwareUpdate* bridgeSoftwareUpdate;

@property (assign, nonatomic) PHSSystemSoftwareUpdateState updateState;

@property (strong, nonatomic) PHSSystemSoftwareUpdateAutoInstall* autoInstall;

@property (strong, nonatomic) NSNumber *install;

@property (strong, nonatomic) NSNumber *checkForUpdate;

@property (strong, nonatomic) NSDate *lastChange;

@property (assign, nonatomic) PHSSystemSoftwareUpdateVersion version;

@end
