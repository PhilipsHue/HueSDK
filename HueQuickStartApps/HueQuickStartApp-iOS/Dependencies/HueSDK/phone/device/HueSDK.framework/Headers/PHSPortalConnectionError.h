/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSHttpError.h"
#import "PHSPortalConnectionErrorCode.h"

@interface PHSPortalConnectionError : PHSHttpError

/**
 The remote connection error code
 */
@property(nonatomic,readonly) PHSPortalConnectionErrorCode error;

@end
