/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"

@interface PHSNumberPair : PHSObject

/**
 The first value of the pair that is contained by this clip type
 */
@property (strong, nonatomic, readonly) NSNumber* value1;

/**
 The second value of the pair that is contained by this clip type
 */
@property (strong, nonatomic, readonly) NSNumber* value2;

/**
 Initializer of this class
 @param value1 first number value of this pair that is contained by this clip type
 @param value2 second number value of this pair that is contained by this clip type
 @return an instance of PHSNumberPair containing the given values
 */
- (instancetype)initWithValue1:(NSNumber *)value1 value2:(NSNumber *)value2;

/**
 Shorthand factory method to create an instance of this class
 @param value1 first number value of this pair that is contained by this clip type
 @param value2 second number value of this pair that is contained by this clip type
 @return an instance of PHSNumberPair containing the given values
 */
+ (instancetype)withValue1:(NSNumber *)value1 value2:(NSNumber *)value2;

/**
 Equal method for this type
 @param clNumberPair clip numberpair value which you want to compare this object to
 @return true if reciever and given object have the same values (or are both none)
 */
- (BOOL)isEqualToCLNumberPair:(PHSNumberPair *)clNumberPair;

@end
