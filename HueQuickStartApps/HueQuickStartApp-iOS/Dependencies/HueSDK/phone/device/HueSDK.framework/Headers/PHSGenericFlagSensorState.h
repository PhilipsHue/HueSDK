/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorState.h"

@interface PHSGenericFlagSensorState : PHSSensorState

/**
 sensor status, expressed as boolean
 */
@property (strong, nonatomic) NSNumber* flag;

@end
