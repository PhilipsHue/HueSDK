/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeResource.h"
#import "PHSScheduleStatus.h"

@class PHSTimePattern;
@class PHSClipAction;

@interface PHSSchedule : PHSBridgeResource

/**
 The schedule description
 */
@property (strong, nonatomic) NSString *scheduleDescription;

/**
 The time when schedule should be executed in UTC
 */
@property (strong, nonatomic) PHSTimePattern *utcTime;

/**
 The time when schedule should be executed in local time (timezone of your bridge)
 */
@property (strong, nonatomic) PHSTimePattern *localTime;

/**
 The time when schedule was created
 */
@property (strong, nonatomic, readonly) NSDate *creationTime;

/**
 The flag for whether auto delete is enabled
 */
@property (strong, nonatomic) NSNumber *autoDelete;

/**
 The schedule status
 */
@property (assign, nonatomic) PHSScheduleStatus scheduleStatus;

/**
 The clip action, which represents that action that should be executed on execution time
 */
@property (strong, nonatomic) PHSClipAction *action;

/**
 Whether the sensor can be recycled by the bridge
 Can only be set on creation
 */
@property (strong, nonatomic) NSNumber *recycle;

@end
