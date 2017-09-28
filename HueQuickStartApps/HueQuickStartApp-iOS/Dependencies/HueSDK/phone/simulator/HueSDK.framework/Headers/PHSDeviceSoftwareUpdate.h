/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import "PHSDomainObject.h"
#import "PHSDeviceSoftwareUpdateState.h"

@interface PHSDeviceSoftwareUpdate : PHSDomainObject

@property (assign, nonatomic) PHSDeviceSoftwareUpdateState updateState;

@property (strong, nonatomic) NSDate *lastInstall;

@end
