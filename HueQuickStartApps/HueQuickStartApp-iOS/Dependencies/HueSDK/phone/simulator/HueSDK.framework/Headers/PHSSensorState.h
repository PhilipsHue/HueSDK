/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDeviceState.h"
#import "PHSAlertMode.h"

@interface PHSSensorState : PHSDeviceState

/**
 The date of when sensor was last updated
 */
@property (strong, nonatomic, readonly) NSDate *lastUpdated;

@end
