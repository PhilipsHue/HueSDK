/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimeIntervalPattern.h"
#import "PHSRecurringDays.h"

@interface PHSRecurringTimeIntervalPattern : PHSTimeIntervalPattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The recurring pattern
 */
@property (assign, nonatomic) PHSRecurringDays recurringDays;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param endTime the end time (only hour, minute and second components will be used)
 @param recurringDays recurring pattern
 @return an instance of PHSTimeIntervalPattern with the given start time and end time set
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime endTime:(NSDateComponents *)endTime recurringDays:(PHSRecurringDays)recurringDays;

/**
 Shorthand factory method to create an instance of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param endTime the end time (only hour, minute and second components will be used)
 @param recurringDays recurring pattern
 @return an instance of PHSTimeIntervalPattern with the given start time and end time set
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime endTime:(NSDateComponents *)endTime recurringDays:(PHSRecurringDays)recurringDays;


@end
