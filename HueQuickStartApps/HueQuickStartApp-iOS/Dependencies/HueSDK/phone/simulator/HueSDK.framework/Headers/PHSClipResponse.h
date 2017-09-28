/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"
#import "PHSAlertMode.h"
#import "PHSGroupType.h"
#import "PHSClipErrorType.h"
#import "PHSLightColorMode.h"
#import "PHSLightEffectMode.h"

@class PHSNumberPair;

@interface PHSClipResponse : PHSDomainObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The successfully changed resource name
 */
@property(strong, nonatomic, readonly) NSString *resourceName;

/**
 The successfully changed alert mode resource value
 */
@property(assign, nonatomic, readonly) PHSAlertMode alertResourceValue;

/**
 The successfully changed error type resource value
 */
@property(assign, nonatomic, readonly) PHSClipErrorType errorTypeResourceValue;

/**
 The successfully changed color mode resource value
 */
@property(assign, nonatomic, readonly) PHSLightColorMode lightColorResourceValue;

/**
 The successfully changed group type resource value
 */
@property(assign, nonatomic, readonly) PHSGroupType groupTypeResourceValue;

/**
 The successfully changed string resource value
 */
@property(nonatomic,strong,readonly) NSString *stringResourceValue;

/**
 The successfully changed boolean resource value
 */
@property(assign, nonatomic, readonly) NSNumber *boolResourceValue;

/**
 The successfully changed double value
 */
@property(assign, nonatomic, readonly) NSNumber *doubleResourceValue;

/**
 The successfully changed integer value
 */
@property(assign, nonatomic, readonly) NSNumber *integerResourceValue;

/**
 The successfully changed date value
 */
@property(nonatomic,strong,readonly) NSDate *dateResourceValue;

/**
 The successfully changed double pair resource value
 */
@property(nonatomic,strong,readonly) PHSNumberPair* numberPairResourceValue;

/**
 The successfully changed string array value
 */
@property(nonatomic,strong,readonly) NSArray* stringArrayResourceValue;

@end
