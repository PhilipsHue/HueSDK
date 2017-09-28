/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

@interface PHSParameterRange : PHSObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The parameter name
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 The values as numbers
 */
@property (strong, nonatomic, readonly) NSArray *valuesAsNumbers;

/**
 The values as strings
 */
@property (strong, nonatomic, readonly) NSArray *valuesAsStrings;

@end
