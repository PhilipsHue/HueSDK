/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTruncatedTimePattern.h"
#import "PHSRecurringDays.h"

@interface PHSRecurringTimePattern : PHSTruncatedTimePattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The recurring pattern
 */
@property (assign, nonatomic) PHSRecurringDays recurringDays;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param recurringDays recurring pattern
 @return an instance of PHSRecurringTimePattern with the given start time and recurring pattern set
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime recurringDays:(PHSRecurringDays)recurringDays;

/**
 Shorthand factory method to create an instance of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param recurringDays recurring pattern
 @return an instance of PHSRecurringTimePattern with the given start time and recurring pattern set
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime recurringDays:(PHSRecurringDays)recurringDays;

@end
