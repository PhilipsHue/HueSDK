/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorState.h"

@interface PHSDaylightSensorState : PHSSensorState

/**
 Whether it's daylight (boolean)
 */
@property (strong, nonatomic) NSNumber *daylight;

@end
