/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation

struct PHBridgeInfo {
    let ipAddress:String
    let uniqueId:String
}

typealias PHBridgeInfoDiscoveryResult = PHBridgeInfo
extension PHBridgeInfoDiscoveryResult {
    init(withDiscoveryResult discoveryResult:PHSBridgeDiscoveryResult) {
        self.ipAddress = discoveryResult.ipAddress
        self.uniqueId = discoveryResult.uniqueId
    }
}
