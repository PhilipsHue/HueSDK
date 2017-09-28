/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

typedef NS_ENUM(NSInteger, PHSClipActionType) {
    PHSClipActionTypeUnknownAction = 0,
    PHSClipActionTypeUpdateDeviceState,
    PHSClipActionTypeUpdateDeviceConfiguration,
    PHSClipActionTypeDeleteDevice,
    PHSClipActionTypeSetGroupState,
    PHSClipActionTypeRecallResource,
    PHSClipActionTypeCreateResource,
    PHSClipActionTypeDeleteResource,
    PHSClipActionTypeUpdateResource
};
