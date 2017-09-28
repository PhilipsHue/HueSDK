/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import "PHSResourceLink.h"
#import "PHSResourceLinkBuilder.h"

@interface PHSResourceLink (Builder)

/**
 create a resourceLink with a builder block
 */
+ (instancetype) resourceLinkWithBlock:(void(^)(PHSResourceLinkBuilder *builder))builderBlock;
  
@end
