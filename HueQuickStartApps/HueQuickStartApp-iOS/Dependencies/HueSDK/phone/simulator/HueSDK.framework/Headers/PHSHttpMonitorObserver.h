/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSHttpRequest.h"
#import "PHSHttpResponse.h"
#import "PHSHttpRequestError.h"

@protocol PHSHttpMonitorObserver

- (void) onRequestPerformed:(PHSHttpRequest*) request status:(int) status;
- (void) onResponseReceived:(PHSHttpResponse*) response error:(PHSHttpRequestError*) error;

@end
