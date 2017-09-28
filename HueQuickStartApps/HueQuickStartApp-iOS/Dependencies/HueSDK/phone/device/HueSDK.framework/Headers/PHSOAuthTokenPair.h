/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"

@interface PHSOAuthTokenPair : PHSObject

- (instancetype)initWithAccessToken:(NSString *)accessToken refreshToken:(NSString *)refreshToken;

/**
 The OAuth access token
 */
@property (strong, nonatomic, readwrite) NSString *accessToken;

/**
 The refresh token, which which to refresh the OAuth access token and the refresh token
 */
@property (strong, nonatomic, readwrite) NSString *refreshToken;

@end
