/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSchedule.h"

@interface PHSTimer : PHSSchedule

/**
 The time this timer was started
 */
@property (strong, nonatomic) NSDate *startTime;

@end
