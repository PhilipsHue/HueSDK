/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation

extension PHSKnownBridge {
    class var lastConnectedBridge:PHSKnownBridge? {
        get {
            let knownBridges:[PHSKnownBridge] = PHSKnownBridges.getAll();
            let sortedKnownBridges:[PHSKnownBridge] = knownBridges.sorted {
                (bridge1, bridge2) -> Bool in
            
                return bridge1.lastConnected < bridge2.lastConnected
            }
        
            return sortedKnownBridges.first
        }
    }
}
