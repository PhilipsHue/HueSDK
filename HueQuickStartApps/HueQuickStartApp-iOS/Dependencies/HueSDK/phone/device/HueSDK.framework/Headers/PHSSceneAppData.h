/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"
#import "PHSReturnCode.h"

@interface PHSSceneAppData : PHSDomainObject

/**
 App specific version of the data field. App should take versioning into account when parsing data string
 */
@property (nonatomic, strong) NSNumber *version;

/**
 App specific data. Free format string
 */
@property (nonatomic, strong) NSString *data;

@end
