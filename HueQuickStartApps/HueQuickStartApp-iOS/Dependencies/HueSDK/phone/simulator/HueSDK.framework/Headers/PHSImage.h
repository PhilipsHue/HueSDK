/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

@interface PHSImage : PHSObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The identifier
 */
@property (strong, nonatomic, readonly) NSString *identifier;

/**
 The type
 */
@property (strong, nonatomic, readonly) NSString *type;

/**
 The color
 */
@property (strong, nonatomic, readonly) NSString *color;

/**
 The uri
 */
@property (strong, nonatomic, readonly) NSString *uri;

/**
 The version
 */
@property (strong, nonatomic, readonly) NSString *version;

@end
