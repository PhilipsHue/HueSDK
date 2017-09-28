/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import "PHSReturnCode.h"

@class PHSError;
@class PHSClipResponse;

typedef void (^PHSBridgeResponseCompletionHandler)(NSArray<PHSClipResponse*> *responses, NSArray<PHSError*> *errors, PHSReturnCode returnCode);
