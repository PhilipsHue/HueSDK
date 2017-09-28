/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorState.h"
#import "PHSButtonEvent.h"

@interface PHSOpenCloseSensorState : PHSSensorState

/**
 Whether the switch is currently open
 */
@property (strong, nonatomic) NSNumber* open;

@end
