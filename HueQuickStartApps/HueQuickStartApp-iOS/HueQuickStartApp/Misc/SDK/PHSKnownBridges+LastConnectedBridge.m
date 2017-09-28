/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSKnownBridges+LastConnectedBridge.h"

@implementation PHSKnownBridges (LastConnectedBridge)

+ (PHSKnownBridge *)lastConnectedBridge {
    NSArray<PHSKnownBridge *>* knownBridges = [PHSKnownBridges getAll];
    
    // Sort by last connected date
    NSArray<PHSKnownBridge *>* sortedKnownBridges = [knownBridges sortedArrayUsingDescriptors:@[
        [NSSortDescriptor sortDescriptorWithKey:@"lastConnected" ascending:NO]
    ]];
    
    return sortedKnownBridges.firstObject;
}

@end
