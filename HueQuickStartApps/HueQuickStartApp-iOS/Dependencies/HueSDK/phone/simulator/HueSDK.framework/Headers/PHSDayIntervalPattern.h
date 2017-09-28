/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimePattern.h"
#import "PHSRecurringDays.h"

@interface PHSDayIntervalPattern : PHSTimePattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The start day of the period in which you want to recur
 Only day and month components will be used
 */
@property (strong, nonatomic) NSDateComponents *startDay;

/**
 The end day of the period in which you want to recur
 Only day and month components will be used
 */
@property (strong, nonatomic) NSDateComponents *endDay;

/**
 The recurring pattern
 */
@property (assign, nonatomic) PHSRecurringDays *recurringDays;

/**
 Initializer of this class
 @param startDay start day of the period in which you want to recur (day and month components will be used)
 @param endDay end day of the period in which you want to recur (day and month components will be used)
 @param recurringDays recurring pattern
 @return an instance of PHSDayIntervalPattern with the given period and recurring pattern set
 */
- (instancetype)initWithStartDay:(NSDateComponents *)startDay endDay:(NSDateComponents *)endDay recurringDays:(PHSRecurringDays)recurringDays;

/**
 Shorthand factory method to create an instance of this class
 @param startDay start day of the period in which you want to recur (day and month components will be used)
 @param endDay end day of the period in which you want to recur (day and month components will be used)
 @return an instance of PHSDayIntervalPattern with the given period and recurring pattern set
 */
+ (instancetype)patternWithStartDay:(NSDateComponents *)startDay endDay:(NSDateComponents *)endDay recurringDays:(PHSRecurringDays)recurringDays;

@end
