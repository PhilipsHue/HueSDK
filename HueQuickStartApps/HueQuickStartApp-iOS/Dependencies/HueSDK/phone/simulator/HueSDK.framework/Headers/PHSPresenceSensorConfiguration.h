/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorConfiguration.h"

@interface PHSPresenceSensorConfiguration : PHSSensorConfiguration

/**
 The sensitivity of the presence sensor
 */
@property (strong, nonatomic) NSNumber* sensitivity;

/**
 The maximum sensitivity of the presence sensor
 */
@property (strong, nonatomic, readonly) NSNumber* maximumSensitivity;

@end
