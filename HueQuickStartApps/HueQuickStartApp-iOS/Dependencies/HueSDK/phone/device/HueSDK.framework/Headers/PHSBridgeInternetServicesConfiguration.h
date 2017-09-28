/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"
#import "PHSConnectionState.h"

@interface PHSBridgeInternetServicesConfiguration : PHSDomainObject

/**
 * @return PHSConnectionStateConnected if at least on of the relevant internet services could be reached, else PHSConnectionStateDisconnected
 */
@property (nonatomic, readonly) PHSConnectionState internet;

/**
 * @return PHSConnectionStateConnected if remote access is available, else PHSConnectionStateDisconnected
 */
@property (nonatomic, readonly) PHSConnectionState remote_access;

/**
 * @return PHSConnectionStateConnected if a time server was reachable in the last n days, else PHSConnectionStateDisconnected
 */
@property (nonatomic, readonly) PHSConnectionState time;

/**
 * @return PHSConnectionStateConnected if the software update server was reachable in the last 24 hours, else PHSConnectionStateDisconnected
 */
@property (nonatomic, readonly) PHSConnectionState sw_update;

@end
