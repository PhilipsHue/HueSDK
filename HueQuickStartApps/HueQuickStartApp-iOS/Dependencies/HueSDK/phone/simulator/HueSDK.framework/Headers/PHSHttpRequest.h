/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"

@interface PHSHttpRequest : PHSObject

/**
 Cancel this request
 */
- (void)cancel;

/**
 get the url
 @return server url
 */
- (NSString*) url;

/**
 get the method to be executed on the url
 @return method (GET, POST, PUT, DELETE)
 */
- (NSString*) method;

/**
 get the body to be sent
 @return body content
 */
- (NSString*) body;

@end
