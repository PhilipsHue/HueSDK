/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimePattern.h"

@interface PHSTimePatternFactory : NSObject 

/**
 Get PHSTimePattern object based on the given string.
 If the string is not a valid time pattern, nil will be returned
 */
+ (PHSTimePattern *)patternByString:(NSString *)timePatternString;

@end
