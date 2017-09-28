/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"
#import "PHSTimePattern.h"
#import "PHSClipConditionAttribute.h"
#import "PHSClipConditionOperator.h"

@class PHSDevice;
@class PHSBridgeResource;

@interface PHSClipCondition : PHSDomainObject

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute equals:(NSObject *)value;

+ (instancetype)conditionForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute equals:(NSObject *)value;

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute lessThan:(NSObject *)value;

+ (instancetype)conditionForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute lessThan:(NSObject *)value;

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute greaterThan:(NSObject *)value;

+ (instancetype)conditionForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute greaterThan:(NSObject *)value;

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attributeHasChanged:(PHSClipConditionAttribute)conditionAttribute;

+ (instancetype)conditionForDevice:(PHSDevice *)device attributeHasChanged:(PHSClipConditionAttribute)conditionAttribute;

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute hasChangedLongerThan:(PHSTimePattern *)value;

+ (instancetype)conditionForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute hasChangedLongerThan:(PHSTimePattern *)value;

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute hasNotChangedFor:(PHSTimePattern *)value;

+ (instancetype)conditionForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute hasNotChangedFor:(PHSTimePattern *)value;

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute hasChangedAtLeastOnceDuring:(PHSTimePattern *)value;

+ (instancetype)conditionForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute hasChangedAtLeastOnceDuring:(PHSTimePattern *)value;

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute isIn:(PHSTimePattern *)value;

+ (instancetype)conditionForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute isIn:(PHSTimePattern *)value;

/**
 Initializer of this class
 @param device the device that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute isNotIn:(PHSTimePattern *)value;

+ (instancetype)conditionForDevice:(PHSDevice *)device attribute:(PHSClipConditionAttribute)conditionAttribute isNotIn:(PHSTimePattern *)value;

/**
 Initializer of this class
 @param resource the resource that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute equals:(NSObject *)value;

+ (instancetype)conditionForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute equals:(NSObject *)value;

/**
 Initializer of this class
 @param resource the resource that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute lessThan:(NSObject *)value;

+ (instancetype)conditionForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute lessThan:(NSObject *)value;

/**
 Initializer of this class
 @param resource the resource that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute greaterThan:(NSObject *)value;

+ (instancetype)conditionForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute greaterThan:(NSObject *)value;

/**
 Initializer of this class
 @param resource the resource that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForResource:(PHSBridgeResource *)resource attributeHasChanged:(PHSClipConditionAttribute)conditionAttribute;

+ (instancetype)conditionForResource:(PHSBridgeResource *)resource attributeHasChanged:(PHSClipConditionAttribute)conditionAttribute;

/**
 Initializer of this class
 @param resource the resource that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute hasChangedLongerThan:(PHSTimePattern *)value;

+ (instancetype)conditionForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute hasChangedLongerThan:(PHSTimePattern *)value;

/**
 Initializer of this class
 @param resource the resource that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute hasChangedAtLeastOnceDuring:(PHSTimePattern *)value;

+ (instancetype)conditionForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute hasChangedAtLeastOnceDuring:(PHSTimePattern *)value;

/**
 Initializer of this class
 @param resource the resource that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute isIn:(PHSTimePattern *)value;

+ (instancetype)conditionForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute isIn:(PHSTimePattern *)value;

/**
 Initializer of this class
 @param resource the resource that belongs to the attribute you want to use in your conditional expression
 @param conditionAttribute the attribute you want to use in your conditional expression
 @param value the value you want to use in your conditional expression
 @return an instance of PHSClipCondition with clip adress, operator and value set for your condition
 */
- (instancetype)initForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute isNotIn:(PHSTimePattern *)value;

+ (instancetype)conditionForResource:(PHSBridgeResource *)resource attribute:(PHSClipConditionAttribute)conditionAttribute isNotIn:(PHSTimePattern *)value;

/**
 The clip address
 */
@property (strong, nonatomic) NSString *address;

/**
 The operator
 */
@property (assign, nonatomic) PHSClipConditionOperator clipOperator;

/**
 The value
 */
@property (strong, nonatomic) NSString *value;

/**
 The attribute
 */
@property (assign, nonatomic) PHSClipConditionAttribute attribute;

/**
 The data type of the value
 */
@property (assign, nonatomic) PHSClipDataType dataType;

/**
 The device where the condition is set on
 @note either the device or resource is set, not both
 */
@property (strong, nonatomic) PHSDevice *device;

/**
 The resource where the condition is set on
 @note either the device or resource is set, not both
 */
@property (strong, nonatomic) PHSBridgeResource *resource;

@end
