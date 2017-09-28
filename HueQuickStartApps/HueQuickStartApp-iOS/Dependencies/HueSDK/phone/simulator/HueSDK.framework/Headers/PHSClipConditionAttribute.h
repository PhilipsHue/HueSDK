/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSClipDataType) {
    PHSDataTypeUndefined = 0,
    PHSDataTypeBoolean,
    PHSDataTypeInteger,
    PHSDataTypeTimePattern
};

typedef NS_ENUM(NSInteger, PHSClipConditionAttribute) {
    PHSUknownAttribute = -1,
    
    PHSClipConditionAttributeSensorStateLastUpdated = 0,
    PHSClipConditionAttributeSensorStateTemperature,
    PHSClipConditionAttributeSensorStateHumidity,
    PHSClipConditionAttributeSensorStateDaylight,
    PHSClipConditionAttributeSensorStateDark,
    PHSClipConditionAttributeSensorStateLightLevel,
    PHSClipConditionAttributeSensorStatePresence,
    PHSClipConditionAttributeSensorStateButtonEvent,
    PHSClipConditionAttributeSensorStateOpen,
    PHSClipConditionAttributeSensorStateFlag,
    PHSClipConditionAttributeSensorStateStatus,
    
    PHSClipConditionAttributeSensorConfigurationBattery,
    PHSClipConditionAttributeSensorConfigurationReachable,
    PHSClipConditionAttributeSensorConfigurationOn,
    PHSClipConditionAttributeSensorConfigurationSunriseOffset,
    PHSClipConditionAttributeSensorConfigurationSunsetOffset,
    PHSClipConditionAttributeSensorConfigurationSensitivity,
    PHSClipConditionAttributeSensorConfigurationMaximumSensitivity,
    PHSClipConditionAttributeSensorConfigurationRadius,
    PHSClipConditionAttributeSensorConfigurationThresholdDark,
    PHSClipConditionAttributeSensorConfigurationThresholdOffset,
    
    PHSClipConditionAttributeLightStateOn,
    PHSClipConditionAttributeLightStateBrightness,
    PHSClipConditionAttributeLightStateHue,
    PHSClipConditionAttributeLightStateSaturation,
    PHSClipConditionAttributeLightStateCt,
    PHSClipConditionAttributeLightStateReachable,
    
    PHSClipConditionAttributeRuleLastTriggered,
    PHSClipConditionAttributeRuleTimesTriggered,
    
    PHSClipConditionAttributeBridgeConfigurationLocalTime,
    
    PHSClipConditionAttributeGroupStateAllOn,
    PHSClipConditionAttributeGroupStateAnyOn
//    PHSClipConditionAttributeGroupStateBrightness,
//    PHSClipConditionAttributeGroupStateLastUpdated,
//    PHSClipConditionAttributeGroupStateLastSwitched
};
