/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSPortalConnectionState) {
    PHSPortalConnectionStateUnknown = -1, // Portal connection state not known
    PHSPortalConnectionStateNone = 0, // Portal connection state not set
    PHSPortalConnectionStateDisconnected = 1, // Not in "polling" state
    PHSPortalConnectionStateConnecting = 2, // In "polling" state and repeated connection attempts are failing
    PHSPortalConnectionStateConnected = 3, // In "polling" state and connection requests are successful
};
