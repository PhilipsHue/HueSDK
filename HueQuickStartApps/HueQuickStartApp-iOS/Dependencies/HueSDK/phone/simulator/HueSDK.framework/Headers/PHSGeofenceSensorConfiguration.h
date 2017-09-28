/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorConfiguration.h"

@interface PHSGeofenceSensorConfiguration : PHSSensorConfiguration

/**
 Radius in meters
 */
@property (nonatomic, strong) NSNumber *radius;

/**
 Device name of the device triggering the fence
 */
@property (nonatomic, strong) NSString *device;

@end
