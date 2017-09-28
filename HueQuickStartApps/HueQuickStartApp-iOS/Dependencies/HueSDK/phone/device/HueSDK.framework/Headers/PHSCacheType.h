/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

/** 
 Enum for the two possible cache types:
 NORMAL: Bridge state gets updated after getting a response from the bridge
 DIRECT: Bridge state gets updated imediately after a command is sent to the bridge.
 DIRECT: Bridge state doesn't get updated
 **/
typedef NS_ENUM(NSInteger, PHSCacheType) {
    PHSCacheTypeUnknown  = 0,
    PHSCacheTypeNormal   = 1,
    PHSCacheTypeDirect   = 2,
    PHSCacheTypeDisabled = 3
};
