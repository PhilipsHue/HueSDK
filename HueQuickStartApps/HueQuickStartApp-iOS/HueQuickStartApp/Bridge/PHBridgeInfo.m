/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHBridgeInfo.h"

@implementation PHBridgeInfo

+ (PHBridgeInfo *)createWithIpAddress:(NSString *)ipAddress andUniqueId:(NSString *)uniqueId {
    PHBridgeInfo* bridgeInfo = [PHBridgeInfo new];
    bridgeInfo.ipAddress = ipAddress;
    bridgeInfo.uniqueId = uniqueId;
    
    return bridgeInfo;
}

@end
