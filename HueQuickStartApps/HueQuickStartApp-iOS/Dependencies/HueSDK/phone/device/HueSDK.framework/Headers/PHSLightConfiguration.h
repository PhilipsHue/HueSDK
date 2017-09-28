/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSDeviceConfiguration.h"

@interface PHSLightConfiguration : PHSDeviceConfiguration

/**
 The Luminaire Unique id. This value will only be filled if a light point is part of multi-source luminaire
 */
@property (strong, nonatomic, readonly) NSString *luminaireUniqueId;

@end

