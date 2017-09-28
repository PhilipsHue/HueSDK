/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

typedef NS_ENUM(NSInteger, PHSPortalConnectionErrorCode) {
    PHSPortalConnectionErrorCodeUnknown,
    PHSPortalConnectionErrorCodeNotAllowed,
    PHSPortalConnectionErrorCodeBadReqeust,
    PHSPortalConnectionErrorCodeLoginRequired,
    PHSPortalConnectionErrorCodeInvalidRequest,
    PHSPortalConnectionErrorCodeInvalidClient,
    PHSPortalConnectionErrorCodeAuthorizationCodeExpired,
    PHSPortalConnectionErrorCodeAccessTokenMissing,
    PHSPortalConnectionErrorCodeAccessTokenBad,
    PHSPortalConnectionErrorCodeAccessTokenExpired
};
