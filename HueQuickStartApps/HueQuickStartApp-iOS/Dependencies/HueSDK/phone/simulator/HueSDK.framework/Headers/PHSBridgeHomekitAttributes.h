/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"

@interface PHSBridgeHomekitAttributes : PHSDomainObject

/**
 Indicates wether or not the paring between the huebridge and homekit should be reset
 */
@property (strong, nonatomic) NSNumber *resetPairing;

@end
