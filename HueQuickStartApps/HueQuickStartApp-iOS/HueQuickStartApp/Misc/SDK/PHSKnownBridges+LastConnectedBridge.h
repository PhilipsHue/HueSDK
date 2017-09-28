/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import <HueSDK/HueSDK.h>

@interface PHSKnownBridges (LastConnectedBridge)

+ (PHSKnownBridge *)lastConnectedBridge;

@end
