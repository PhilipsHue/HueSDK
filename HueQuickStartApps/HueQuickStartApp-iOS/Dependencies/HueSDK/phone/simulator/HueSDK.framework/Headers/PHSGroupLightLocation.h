/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSDomainObject.h"

@interface PHSGroupLightLocation : PHSDomainObject

/**
 The light identifier for the locations
 */
@property (nonatomic, strong) NSString *lightIdentifier;

/**
 Position [x,y,z] on a for the given light ID relative to reference point as
 indicated in class with [0.0,0.0,0.0] in the center. If a reference point 
 is given then negative values are left/back/down from center and positive 
 values are right/front/up from center.
 */
@property (nonatomic, strong) NSNumber *x;
@property (nonatomic, strong) NSNumber *y;
@property (nonatomic, strong) NSNumber *z;

@end


