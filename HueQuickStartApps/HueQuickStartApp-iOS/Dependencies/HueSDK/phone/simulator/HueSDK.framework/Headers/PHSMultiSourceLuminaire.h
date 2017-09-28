/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSLightPoint.h"
#import "PHSCompoundLight.h"

@interface PHSMultiSourceLuminaire : PHSCompoundLight

/**
 Whether the luminaire object is complete and doesn't
 contain nullptr light sources, which are not found during discovery
 @return true if complete, false otherwise
 */
- (BOOL)isComplete;

@end
