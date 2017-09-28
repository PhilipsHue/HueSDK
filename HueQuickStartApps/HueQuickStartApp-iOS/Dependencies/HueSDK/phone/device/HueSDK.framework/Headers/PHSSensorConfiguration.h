/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDeviceConfiguration.h"
#import "PHSAlertMode.h"

@interface PHSSensorConfiguration : PHSDeviceConfiguration

/**
 The url of the sensor
 */
@property (strong, nonatomic) NSString *url;

/**
 The battery state, usually expressed in percentages
 Range: 0-100
 */
@property (strong, nonatomic) NSNumber *battery;

/**
 Whether the sensor is reachable
 */
@property (strong, nonatomic) NSNumber *reachable;

/**
 Whether the sensor is on
 */
@property (strong, nonatomic) NSNumber *on;

/**
 The alert to set the sensor to.
 "none" (no alert),
 "select" (1 indication cycle),
 "lselect" (indication cycles for 30 seconds or until value none is set)
 */
@property (assign, nonatomic) PHSAlertMode alert;

/**
 Whether the sensor is in usertest mode
 When set to on activates or extends usertest of device by 120s. In usertest sensors
 report changes in state faster and indicate state changes on device LED (if applicable)
 */
@property (strong, nonatomic) NSNumber *usertest;

/**
 Whether the sensor can be recycled by the bridge
 Can only be set on creation
 */
@property (strong, nonatomic) NSNumber *recycle;

/**
 Whether the led indication is on
 */
@property (strong, nonatomic) NSNumber *ledIndication;

/**
 An array of pending (set, but no yet committed) properties, e.g. PHSClipAttributeSensitivity, PHSClipAttributeLedIndication
 */
@property (strong, nonatomic) NSArray *pending;

@end
