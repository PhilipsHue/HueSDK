/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSBridgeConnectionType) {
    PHSBridgeConnectionTypeNone        = 0,
    PHSBridgeConnectionTypeLocal       = 1,
    PHSBridgeConnectionTypeRemote      = 2,
    PHSBridgeConnectionTypeLocalRemote = 3,
    PHSBridgeConnectionTypeRemoteLocal = 4
};
