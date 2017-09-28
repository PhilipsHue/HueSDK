/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"
#import "PHSReturnCode.h"

@interface PHSPersistence : PHSObject

/**
 Get storage location
 @return The storage location where files will be stored
 */
+ (NSString *)storageLocation;

/**
 Set storage location
 @param storageLocation The storage location where files will be stored
 @param deviceId        The device id which is used for encrypting the persistence
 */
+ (PHSReturnCode)setStorageLocation:(NSString*)storageLocation andDeviceId:(NSString*)deviceId;

@end
