/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSReturnCode.h"

@class PHSOAuthTokenPair;

@protocol PHSPortalConnection <NSObject>

/**
 @return the URL to use to login (on meethue.com)
 */
- (NSString*)getLoginURL;

/**
 Set the authorization URL that was received by the callback URI
 @param authorizationUrl The url that was recieved after authorizing on meethue.com (@see PHSRemoteBridgeConnectionOptions)
 @return PHSReturnCodeSuccess, PHSReturnCodeWrongParameter, PHSReturnCodeInvalidRequest, PHSReturnCodeInvalidClient, PHSReturnCodeAuthorizationCodeExpired, PHSreturnCodeStateMismatch
 */
- (PHSReturnCode)setAuthorizationUrl:(NSString *)authorizationUrl;

/**
 Set the access token and refresh token (will be deprecated)
 */
- (void)setAccessTokens:(PHSOAuthTokenPair*)tokenPair;

/**
 Invalidate the authorization of the client
 @return PHSReturnCodeSuccess or PHSReturnCodeDoesNotExist
 */
- (PHSReturnCode)invalidateAuthorization;

@end
