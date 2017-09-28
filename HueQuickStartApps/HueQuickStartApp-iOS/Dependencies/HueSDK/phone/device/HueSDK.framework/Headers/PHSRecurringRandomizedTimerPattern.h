/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSRecurringTimerPattern.h"

@interface PHSRecurringRandomizedTimerPattern : PHSRecurringTimerPattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The random element which is added to the start date time
 Only hour, minute and second components are used
 */
@property (strong, nonatomic) NSDateComponents *randomElement;

/**
 Initializer of this class
 @param startTime      the start time (only hour, minute and second components will be used)
 @param randomElement  the random element which is added to the start date time (only hour, minute and second components are used)
 @param recurringTimes amount of times it needs to recur
 @return an instance of PHSRecurringRandomizedTimerPattern with the given start time set and random element set
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime recurringTimes:(NSInteger)recurringTimes randomElement:(NSDateComponents *)randomElement;

/**
 Shorthand factory method to create an instance of this class
 @param startTime the  start time (only hour, minute and second components will be used)
 @param randomElement  the random element which is added to the start date time (only hour, minute and second components are used)
 @param recurringTimes amount of times it needs to recur
 @return an instance of PHSRecurringRandomizedTimerPattern with the given start time and random element set
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime recurringTimes:(NSInteger)recurringTimes randomElement:(NSDateComponents *)randomElement;

@end
