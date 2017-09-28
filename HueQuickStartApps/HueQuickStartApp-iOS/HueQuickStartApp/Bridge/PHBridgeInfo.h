/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

@interface PHBridgeInfo : NSObject

@property (nonatomic, strong) NSString* ipAddress;
@property (nonatomic, strong) NSString* uniqueId;

+ (PHBridgeInfo *)createWithIpAddress:(NSString *)ipAddress andUniqueId:(NSString *)uniqueId;

@end
