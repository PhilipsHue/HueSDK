/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

typedef NS_ENUM(NSInteger, PHSDomainType) {
    PHSDomainTypeUnknown               = 0,
    PHSDomainTypeDomainObject          = 1,
    
    /*
     response types
     */
    PHSDomainTypeClipResponse                = 2,
    PHSDomainTypeError                       = 3,
    PHSDomainTypeClipError                   = 4,
    PHSDomainTypeHttpError                   = 5,
    PHSDomainTypeHttpRequestError            = 6,
    PHSDomainTypePortalConnectionError       = 7,
    PHSDomainTypePushNotificationError       = 8,
    PHSDomainTypeSdkError                    = 9,
    
    /**
     main types
     */
    PHSDomainTypeBridgeVersion        = 11,
    PHSDomainTypeRemoteBridge         = 12,
    PHSDomainTypeResource             = 21,
    PHSDomainTypeDevice               = 22,
    PHSDomainTypeCompoundDevice       = 23,
    PHSDomainTypeDeviceSearchStatus   = 24,
    
    /**
     resources
     */
    PHSDomainTypeWhitelistEntry       = 101,
    PHSDomainTypeGroup                = 102,
    PHSDomainTypeScene                = 103,
    PHSDomainTypeRule                 = 104,
    PHSDomainTypeAction               = 106,
    PHSDomainTypeSchedule             = 107,
    PHSDomainTypeTimer                = 108,
    PHSDomainTypeSceneAppData         = 109,
    PHSDomainTypeResourceLink         = 110,
    PHSDomainTypeTimeZones            = 111,
    PHSDomainTypeCapabilities         = 112,
    PHSDomainTypeResourceCapabilities = 113,
    PHSDomainTypeSceneCapabilities    = 114,
    PHSDomainTypeSensorCapabilities   = 115,
    PHSDomainTypeRuleCapabilities     = 116,
    
    /**
     group resources
     */
    PHSDomainTypeLightGroup          = 121,
    PHSDomainTypeLuminaireGroup      = 122,
    PHSDomainTypeLightSourceGroup    = 123,
    
    /**
     action resources
     */
    PHSDomainTypeSceneAction         = 141,
    PHSDomainTypeLightAction         = 142,
    PHSDomainTypeClipAction          = 143,
    PHSDomainTypeClipCondition       = 144,
    
    /**
     devices
     */
    PHSDomainTypeBridge               = 201,
    PHSDomainTypeLight                = 202,
    PHSDomainTypeSensor               = 203,
    PHSDomainTypeSwitch               = 204,
    
    /**
     sensor devices
     */
    PHSDomainTypeOpenCloseSensor         = 231,
    PHSDomainTypeGenericFlagSensor       = 232,
    PHSDomainTypeGenericStatusSensor     = 233,
    PHSDomainTypePresenceSensor          = 234,
    PHSDomainTypeGeofenceSensor          = 235,
    PHSDomainTypeTemperatureSensor       = 236,
    PHSDomainTypeHumiditySensor          = 237,
    PHSDomainTypeDaylightSensor          = 238,
    PHSDomainTypeLightLevelSensor        = 239,
    
    /**
     compound devices
     */
    PHSDomainTypeMultiSourceLuminaire   = 251,
    PHSDomainTypeLightSource            = 252,
    PHSDomainTypeFactoryLuminaire       = 253,
    PHSDomainTypeUserCreatedLuminaire   = 254,
    PHSDomainTypeCompoundLight          = 255,
    
    PHSDomainTypeCompoundSensor                      = 256,
    PHSDomainTypePresenceLightLevelTemperatureSensor = 257,

    /**
     device states
     */
    PHSDomainTypeDeviceState         = 300,
    PHSDomainTypeBridgeState         = 301,
    PHSDomainTypeLightState          = 302,
    PHSDomainTypeSensorState         = 303,
    PHSDomainTypeSwitchState         = 304,
    
    /**
     sensor device states
     */
    PHSDomainTypeOpenCloseSensorState      = 331,
    PHSDomainTypeGenericFlagSensorState    = 332,
    PHSDomainTypeGenericStatusSensorState  = 333,
    PHSDomainTypePresenceSensorState       = 334,
    PHSDomainTypeGeofenceSensorState       = 335,
    PHSDomainTypeTemperatureSensorState    = 336,
    PHSDomainTypeHumiditySensorState       = 337,
    PHSDomainTypeDaylightSensorState       = 338,
    PHSDomainTypeLightLevelSensorState     = 339,
    
    /**
     device configurations
     */
    PHSDomainTypeDeviceConfiguration = 400,
    PHSDomainTypeBridgeConfiguration = 401,
    PHSDomainTypeLightConfiguration  = 402,
    PHSDomainTypeSensorConfiguration = 403,
    PHSDomainTypeSwitchConfiguration = 404,
    
    /**
     light device configurations
     */
    PHSDomainTypeDimmableLightConfiguration = 411,
    PHSDomainTypeColorLightConfiguration    = 412,
    
    /**
     sensor device states
     */
    PHSDomainTypeOpenCloseSensorConfiguration      = 421,
    PHSDomainTypeGenericFlagSensorConfiguration    = 422,
    PHSDomainTypeGenericStatusSensorConfiguration  = 423,
    PHSDomainTypePresenceSensorConfiguration       = 434,
    PHSDomainTypeGeofenceSensorConfiguration       = 425,
    PHSDomainTypeTemperatureSensorConfiguration    = 426,
    PHSDomainTypeHumiditySensorConfiguration       = 427,
    PHSDomainTypeDaylightSensorConfiguration       = 428,
    PHSDomainTypeLightLevelSensorConfiguration     = 429,
    
    /**
     bridge configurations
     */
    PHSDomainTypeBridgeConfigurationBackup              = 440,
    PHSDomainTypeBridgeConfigurationNetwork             = 441,
    PHSDomainTypeBridgeConfigurationPortal              = 442,
    PHSDomainTypeBridgeConfigurationSoftwareUpdate      = 443,
    PHSDomainTypeBridgeConfigurationTime                = 444,
    PHSDomainTypeBridgeConfigurationVersion             = 445,
    PHSDomainTypeBridgeConfigurationHomekit             = 446,
};



