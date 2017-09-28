/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

@class PHSBridge;

@protocol PHSFindNewDevicesCallback <NSObject>

/**
 Callback that can get called regularly during the bridge's device search
 */
- (void)bridge:(PHSBridge*)bridge didFindDevices:(NSArray<PHSDevice *> *)devices errors:(NSArray<PHSError *> *)errors;

/**
 Callback that is called when the bridge has finished searching
 */
- (void)bridge:(PHSBridge*)bridge didFinishSearch:(NSArray<PHSError *> *)errors;

@end
