/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorState.h"
#import "PHSButtonEvent.h"

@interface PHSSwitchState : PHSSensorState

/**
 Code of last switch event
 */
@property (assign, nonatomic) PHSButtonEvent buttonEvent;

@end
