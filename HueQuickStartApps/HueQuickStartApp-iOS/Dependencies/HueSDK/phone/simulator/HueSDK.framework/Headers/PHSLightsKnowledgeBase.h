/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSKnowledgeBase.h"

@interface PHSLightsKnowledgeBase : PHSKnowledgeBase

/**
 The gamuts
 */
@property (strong, nonatomic, readonly) NSDictionary *gamuts;

/**
 The lights
 */
@property (strong, nonatomic, readonly) NSArray *lights;

@end
