/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorState.h"

@interface PHSHumiditySensorState : PHSSensorState

/**
 Whether presence is detected
 */
@property (strong, nonatomic) NSNumber *humidity;

@end
