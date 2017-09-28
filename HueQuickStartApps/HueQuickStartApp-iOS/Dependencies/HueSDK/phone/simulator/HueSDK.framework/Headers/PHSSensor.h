/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDevice.h"

@class PHSSensorState;
@class PHSSensorConfiguration;

typedef NS_ENUM(NSInteger, PHSSensorSubType) {
    PHSSensorSubTypeUnknown = -1,
    PHSSensorSubTypeCLIP = 0,
    PHSSensorSubTypeZLL = 1,
    PHSSensorSubTypeZGP = 2
};

@interface PHSSensor : PHSDevice

/**
 Sensor type (e.g. CLIPSwitch, ZLLSwitch)
 */
@property (strong, nonatomic) NSString *type;

/**
 Sensor sub type
 */
@property (assign, nonatomic, readonly) PHSSensorSubType subType;

/**
 State of the sensor
 */
@property (strong, nonatomic, readonly) PHSSensorState *sensorState;

/**
 Configuration of the sensor
 */
@property (strong, nonatomic) PHSSensorConfiguration *sensorConfiguration;

/*
 Set the sensor state
 @param sensorState state to set
 @return PHSSuccess or PHSUnsupportedParameterType
 */
- (PHSReturnCode)setSensorState:(PHSSensorState *)sensorState;

@end
