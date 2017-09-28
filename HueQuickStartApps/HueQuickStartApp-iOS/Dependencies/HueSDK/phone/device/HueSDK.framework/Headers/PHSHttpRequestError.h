/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSError.h"

@interface PHSHttpRequestError : PHSError

typedef NS_ENUM(NSInteger, PHSHttpRequestErrorCode) {
    PHSHttpRequestErrorCodeSuccess            = 0, /* no error occurred */
    PHSHttpRequestErrorCodeUndefined          = 1, /* unknown or not defined */
    PHSHttpRequestErrorCodeCanceled           = 2, /* request was canceled */
    PHSHttpRequestErrorCodeCannotResolveHost  = 3, /* CURLE_COULDNT_RESOLVE_HOST (6) */
    PHSHttpRequestErrorCodeCannotConnect      = 4, /* CURLE_COULDNT_CONNECT (7) */
    PHSHttpRequestErrorCodeTimeout            = 5, /* CURLE_OPERATION_TIMEDOUT (28) */
    PHSHttpRequestErrorCodeServerReset        = 6, /* CURLE_GOT_NOTHING (52) */
    PHSHttpRequestErrorCodeInvalidCertificate = 7, /* invalid certificate */
    PHSHttpRequestErrorCodeGatewayTimeout     = 8, /* gateway timeout */
};

/**
 The http error message
 */
@property(strong, nonatomic, readonly) NSString *errorMessage;

/**
 The http error code
 */
@property(assign, nonatomic, readonly) PHSHttpRequestErrorCode errorCode;

@end
