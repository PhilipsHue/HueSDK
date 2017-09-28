/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSRecurringTimePattern.h"

@interface PHSRecurringRandomizedTimePattern : PHSRecurringTimePattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The random element which is added to the start date time
 Only hour, minute and second components are used
 */
@property (strong, nonatomic) NSDateComponents *randomElement;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param recurringDays bitwise action can be used to choose multiple days
 @param randomElement the random element which is added to the start date time (only hour, minute and second components are used)
 @return an instance of PHSRecurringRandomizedTimerPattern with the given start time set and random element set
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime recurringDays:(PHSRecurringDays)recurringDays randomElement:(NSDateComponents *)randomElement;

/**
 Shorthand factory method to create an instance of this class
 @param startTime     the start time (only hour, minute and second components will be used)
 @param recurringDays bitwise action can be used to choose multiple days
 @param randomElement the random element which is added to the start date time (only hour, minute and second components are used)
 @return an instance of PHSRecurringRandomizedTimerPattern with the given start time and random element set
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime recurringDays:(PHSRecurringDays)recurringDays randomElement:(NSDateComponents *)randomElement;

@end
