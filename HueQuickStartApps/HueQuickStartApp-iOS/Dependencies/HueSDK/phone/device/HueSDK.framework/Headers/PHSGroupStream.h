/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSDomainObject.h"
#import "PHSProxyMode.h"

@interface PHSGroupStream : PHSDomainObject

/**
 Writing true activates the stream, false disables it
 */
@property (nonatomic, strong) NSNumber *active;

/**
 Whitelist entry which activated the stream
 */
@property (nonatomic, strong, readonly) NSString *owner;

/**
 auto: The bridge will select a proxynode automatically.
 manual: The proxynode has been set manually
 */
@property (nonatomic, assign) PHSProxyMode proxyMode;

/**
 The proxynode relays the entertainment traffic and should be 
 located in or close to all entertainment lamps in this group
 Can be "/bridge" or "/lights/<light-id>"
 */
@property (nonatomic, strong) NSString *proxyNode;

@end


