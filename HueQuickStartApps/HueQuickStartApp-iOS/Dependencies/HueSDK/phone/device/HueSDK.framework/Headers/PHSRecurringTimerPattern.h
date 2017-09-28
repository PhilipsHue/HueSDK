/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimerPattern.h"
#import "PHSRecurringDays.h"

@interface PHSRecurringTimerPattern : PHSTimerPattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The amount of times it needs to recur
 */
@property (assign, nonatomic) NSInteger recurringTimes;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param recurringTimes amount of times it needs to recur
 @return an instance of PHSRecurringTimerPattern with the given start time and recurring times set
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime recurringTimes:(NSInteger)recurringTimes;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param recurringTimes amount of times it needs to recur
 @return an instance of PHSRecurringTimerPattern with the given start time and recurring times set
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime recurringTimes:(NSInteger)recurringTimes;

@end
