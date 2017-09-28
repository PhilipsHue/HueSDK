/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

@interface PHSDigestFunction : NSObject

typedef size_t(*DigestFunctionPointer)(const char*, const char*, const char*, const char*, const char*, const char*, char*, size_t);

/**
 Set reference to the digest function
 @param digestFunctionPointer The function pointer
 */
+ (void)setDigestFunctionPointer:(DigestFunctionPointer)digestFunctionPointer;

@end
