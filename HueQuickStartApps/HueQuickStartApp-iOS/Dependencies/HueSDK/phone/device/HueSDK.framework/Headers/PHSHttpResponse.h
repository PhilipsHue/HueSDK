/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"

@interface PHSHttpResponse : PHSObject

/**
 The http body
 */
@property (strong, nonatomic, readonly) NSString *body;

/**
 The http status code
 */
@property (assign, nonatomic, readonly) int statusCode;

@end
