/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeResource.h"
#import "PHSBridgeResourceCapabilities.h"
#import "PHSDomainType.h"

@interface PHSBridgeCapabilities : PHSBridgeResource

@property (nonatomic, strong, readonly) NSDictionary<NSNumber*, PHSBridgeResourceCapabilities*>* bridgeResourceCapabilities;

- (PHSBridgeResourceCapabilities*) capabilitiesForDomainType:(PHSDomainType)domainType;

@end
