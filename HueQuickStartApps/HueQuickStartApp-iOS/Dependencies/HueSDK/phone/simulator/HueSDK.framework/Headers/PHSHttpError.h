/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSError.h"

@interface PHSHttpError : PHSError

/**
 The http error message
 */
@property(strong, nonatomic, readonly) NSString *errorMessage;

/**
 The http error code
 */
@property(assign, nonatomic, readonly) NSInteger errorCode;

@end
