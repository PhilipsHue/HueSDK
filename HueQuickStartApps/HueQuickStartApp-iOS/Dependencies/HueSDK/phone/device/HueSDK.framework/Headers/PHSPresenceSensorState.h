/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorState.h"
#import "PHSButtonEvent.h"

@interface PHSPresenceSensorState : PHSSensorState

/**
 Whether presence is detected
 */
@property (strong, nonatomic) NSNumber* presence;

@end
