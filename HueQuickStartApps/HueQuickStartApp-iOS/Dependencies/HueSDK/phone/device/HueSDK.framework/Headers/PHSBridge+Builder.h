/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import "PHSBridge.h"
#import "PHSBridgeBuilder.h"

@interface PHSBridge (Builder)

+ (instancetype) bridgeWithBlock:(void(^)(PHSBridgeBuilder *builder))builderBlock withAppName:(NSString*)appName withDeviceName:(NSString*)deviceName;
  
@end
