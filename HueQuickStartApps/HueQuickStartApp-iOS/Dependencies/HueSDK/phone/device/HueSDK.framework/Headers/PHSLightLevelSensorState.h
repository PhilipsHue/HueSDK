/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorState.h"

@interface PHSLightLevelSensorState : PHSSensorState

/**
 Whether it's daylight
 */
@property (strong, nonatomic, readonly) NSNumber *daylight;

/**
 Whether it's dark
 */
@property (strong, nonatomic, readonly) NSNumber *dark;
 
/**
 The light level measured by the sensor
 */
@property (strong, nonatomic) NSNumber *lightLevel;

@end
