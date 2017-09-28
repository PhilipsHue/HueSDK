
/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeResource.h"
#import "PHSRuleStatus.h"

@class PHSClipAction;
@class PHSClipCondition;

@interface PHSRule : PHSBridgeResource

/**
 The owner of the rule
 */
@property (strong, nonatomic) NSString *owner;

/**
 The creation date of the rule
 */
@property (strong, nonatomic, readonly) NSDate *created;

/**
 The conditions of the rule
 */
@property (strong, nonatomic) NSArray *conditions;

/**
 The actions of the rule
 */
@property (strong, nonatomic) NSArray *actions;

/**
 The rule status
 */
@property (assign, nonatomic) PHSRuleStatus ruleStatus;

/**
 The time when the rule has been triggered for the last time, as object
 */
@property (strong, nonatomic, readonly) NSDate *lastTriggered;

/**
 How many times the rule got already triggered
 */
@property (strong, nonatomic, readonly) NSNumber *timesTriggered;

/**
 Whether the sensor can be recycled by the bridge
 Can only be set on creation
 */
@property (strong, nonatomic) NSNumber *recycle;

/**
 Add action for the rule
 @param action The action to add
 */
- (void)addAction:(PHSClipAction *)action;

/**
 Add condition for the rule
 @param condition The condition to add
 */
- (void)addCondition:(PHSClipCondition *)condition;

@end
