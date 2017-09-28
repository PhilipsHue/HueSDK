/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import "PHSResourceLink.h"

@interface PHSResourceLinkBuilder : NSObject

/**
 initialize this builder
 */
- (instancetype)init;

/**
 deallocate this builder
 */
- (void)dealloc;

/**
 set the name of the resource link
 */
- (void)setName:(NSString *)name;

/**
 set the identifier of the resource link
 */
- (void)setIdentifier:(NSString *)identifier;

/**
 set the description of the resource link
 */
- (void)setResourceLinkDescription:(NSString *)resourceLinkDescription;

/**
 set the type of the resource link
 */
- (void)setResourceLinkType:(PHSResourceLinkType)resourceLinkType;

/**
 set the class ID of the resource link
 */
- (void)setClassId:(NSNumber *)classId;

/**
 set the owner of the resource link
 */
- (void)setOwner:(NSString *)owner;

/**
 set the recycle flag
 */
- (void)setRecycle:(NSNumber *)recycle;

/**
 set a list of resource links
 this removes any preexisting links
 */

- (void)setLinks:(NSArray *)links;

/**
 Add a link to the list of links
 */
- (void)addLink:(PHSDomainObject*)link;

/**
 @return a newly built ResourceLink
 */
- (PHSResourceLink*) build;

@end
