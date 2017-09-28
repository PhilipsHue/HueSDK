/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

@interface PHSGamut : PHSObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The identifier
 */
@property (strong, nonatomic, readonly) NSString *identifier;

/**
 The colors
 */
@property (strong, nonatomic, readonly) NSDictionary *colorPoints;

@end
