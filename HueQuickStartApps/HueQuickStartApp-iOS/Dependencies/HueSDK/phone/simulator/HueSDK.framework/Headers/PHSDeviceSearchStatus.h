/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"

@class PHSDeviceSearchDeviceInfo;

@interface PHSDeviceSearchStatus : PHSDomainObject

/**
 Whether the search is active
 @return true when active, false otherwise. Nullptr if not set
 */
@property (strong, nonatomic, readonly) NSNumber *active;

/**
 The last scan date
 @return The last scan date. nil if not set
 */
@property (strong, nonatomic, readonly) NSDate *lastScan;

/**
 The list with found device info, which contains the id, name and type
 of each found device
 @return list with found devices
 */
@property (strong, nonatomic, readonly) NSArray<PHSDeviceSearchDeviceInfo*> *foundDevicesInfo;

@end
