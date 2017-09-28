/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensor.h"
#import "PHSBridgeResourceCapabilities.h"

@interface PHSBridgeSensorCapabilities : PHSBridgeResourceCapabilities

- (NSNumber *)availableSensorsForSubType:(PHSSensorSubType)subType;

@end
