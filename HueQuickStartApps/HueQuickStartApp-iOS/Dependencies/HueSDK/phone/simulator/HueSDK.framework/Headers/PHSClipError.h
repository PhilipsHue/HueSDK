/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSError.h"
#import "PHSClipErrorType.h"

@interface PHSClipError : PHSError

/**
 The error type
 */
@property (assign, nonatomic, readonly) PHSClipErrorType errorType;

/**
 The error address
 */
@property (strong, nonatomic, readonly) NSString *errorAddress;

/**
 The error description
 */
@property (strong, nonatomic, readonly) NSString *errorDescription;

@end
