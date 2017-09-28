/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSError.h"
#import "PHSReturnCode.h"

@interface PHSSDKError : PHSError

/**
 The http error message
 */
@property(strong, nonatomic, readonly) NSString *errorMessage;

/**
 The SDK error code
 */
@property(assign, nonatomic, readonly) PHSReturnCode errorCode;

@end
