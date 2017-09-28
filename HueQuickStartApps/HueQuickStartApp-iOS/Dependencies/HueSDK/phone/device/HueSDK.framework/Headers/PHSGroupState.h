/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSDomainObject.h"

@interface PHSGroupState : PHSDomainObject 

/**
 It is true if any lamp is on.
 Readonly value.
 */
@property (nonatomic, strong,readonly) NSNumber *any_on;

/**
 It is true if all lamps are on.
 Readonly value.
 */
@property (strong, nonatomic,readonly) NSNumber *all_on;

@end


