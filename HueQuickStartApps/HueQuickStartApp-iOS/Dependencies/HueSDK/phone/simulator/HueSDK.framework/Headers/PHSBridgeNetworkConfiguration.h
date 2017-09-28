/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"

@interface PHSBridgeNetworkConfiguration : PHSDomainObject

/**
 The IP address of this bridge
 */
@property (strong, nonatomic) NSString *ipAddress;

/**
 The MAC address of this bridge
 */
@property (nonatomic, strong,readonly) NSString *macAddress;

/**
 The DHCP setting of the bridge, set to true or false to respectively enable or disable DHCP
 */
@property (strong, nonatomic) NSNumber *dhcp;

/**
 The netmask to use
 */
@property (strong, nonatomic) NSString *netmask;

/**
 The gateway to use
 */
@property (strong, nonatomic) NSString *gateway;

/**
 The current Zigbee wireless frequency channel used by the bridge
 */
@property (strong, nonatomic) NSNumber *zigbeeChannel;

@end
