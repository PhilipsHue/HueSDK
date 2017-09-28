/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeResourceCapabilities.h"

@interface PHSBridgeRuleCapabilities : PHSBridgeResourceCapabilities

@property (nonatomic, strong, readonly) NSNumber* availableConditions;

@property (nonatomic, strong, readonly) NSNumber* availableActions;

@end
