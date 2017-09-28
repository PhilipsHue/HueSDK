/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeResource.h"
#import "PHSResourceLinkType.h"

@interface PHSResourceLink : PHSBridgeResource

/**
 Set the description of this resource link
 */
@property (strong, nonatomic) NSString *resourceLinkDescription;

/**
 Get the type of this resource link
 */
@property (assign, nonatomic) PHSResourceLinkType resourceLinkType;

/**
 The class ID of the resource link
 */
@property (strong, nonatomic) NSNumber *classId;

/**
 The owner of the resource link
 */
@property (strong, nonatomic) NSString *owner;

/**
 The recycle setting
 */
@property (strong, nonatomic) NSNumber *recycle;

/**
 Get a list of the actual resource links. This list contains objects of type PHSDomainObject
 */
@property (strong, nonatomic) NSArray *links;

@end
