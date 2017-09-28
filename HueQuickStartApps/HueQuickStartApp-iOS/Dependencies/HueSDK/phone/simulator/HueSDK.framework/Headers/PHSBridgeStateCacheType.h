/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

typedef NS_ENUM(NSInteger, PHSBridgeStateCacheType) {
    PHSBridgeStateCacheTypeFullConfig                    = 0,
    PHSBridgeStateCacheTypeBridgeConfig                  = 1,
    PHSBridgeStateCacheTypeLightsAndGroups               = 2,
    PHSBridgeStateCacheTypeScenes                        = 3,
    PHSBridgeStateCacheTypeSensorsAndSwitches            = 4,
    PHSBridgeStateCacheTypeRules                         = 5,
    PHSBridgeStateCacheTypeSchedulesAndTimers            = 6,
    PHSBridgeStateCacheTypeResourceLinks                 = 7,
    PHSBridgeStateCacheTypeDeviceSearchStatus            = 8
};

