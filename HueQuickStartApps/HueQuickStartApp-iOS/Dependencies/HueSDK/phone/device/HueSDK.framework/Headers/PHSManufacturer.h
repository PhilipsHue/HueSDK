/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

@interface PHSManufacturer : PHSObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The identifier
 */
@property (strong, nonatomic, readonly) NSString *identifier;

/**
 The manufacturer
 */
@property (strong, nonatomic, readonly) NSString *manufacturer;

@end
