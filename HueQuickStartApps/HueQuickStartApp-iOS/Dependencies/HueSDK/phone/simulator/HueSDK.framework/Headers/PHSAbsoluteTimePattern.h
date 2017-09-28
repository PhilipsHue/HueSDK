/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimePattern.h"

@interface PHSAbsoluteTimePattern : PHSTimePattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The start date
 Only day, month, year, hour, minute and second components will be used
 */
@property (strong, nonatomic) NSDateComponents *startDateTime;

/**
 Initializer of this class
 @param startDateTime the start date (only day, month, year, hour, minute and second components will be used)
 @return an instance of PHSAbsoluteTimePattern with the given start date set
 */
- (instancetype)initWithStartDateTime:(NSDateComponents *)startDateTime;

/**
 Shorthand factory method to create an instance of this class
 @param startDateTime the start date (only day, month, year, hour, minute and second components will be used)
 @return an instance of PHSAbsoluteTimePattern with the given start date set
 */
+ (instancetype)patternWithStartDateTime:(NSDateComponents *)startDateTime;

@end

