/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"
#import "PHSKnowledgeBaseType.h"

@class PHSKnowledgeBase;

@interface PHSKnowledgeBaseLibrary : PHSObject

/**
 The schema version
 */
@property (strong, nonatomic, readonly) NSString *schemaVersion;

/**
 The version
 */
@property (strong, nonatomic, readonly) NSString *version;

/**
 Get knowledge by the given type
 @return The knowledge base
 */
- (PHSKnowledgeBase *)getKnowledgeBase:(PHSKnowledgeBaseType)type;

/**
 Get the knowledge library singleton
 @return The knowledge base library
 */
+ (id)instance;

@end
