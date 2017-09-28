/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol PHBridgeSelectionViewControllerSegueCoordinator : SegueCoordinator {
    func bridgeSelectionController(_ controller:PHBridgeSelectionViewController, didSelectBridge bridge:PHBridgeInfo)
    func bridgeSelectionControllerDidRefreshBridges(_ controller:PHBridgeSelectionViewController)
}

let PHBridgeSelectionCellIdentifier:String = "DiscoveredBridgeCell";

extension UITableViewCell {
    func setBridgeInfo(_ bridgeInfo:PHBridgeInfo) {
        self.textLabel?.text = bridgeInfo.ipAddress
        self.detailTextLabel?.text = bridgeInfo.uniqueId
    }
}

class PHBridgeSelectionViewController : UITableViewController, NavigationHelping {
    var bridgeList:[PHBridgeInfo] = []
    
    lazy var segueCoordinator:PHBridgeSelectionViewControllerSegueCoordinator = {
       return HueQuickStartAppSegueCoordinator()
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        configureNavigation()
    }
    
    @IBAction func refreshButtonAction() {
        self.segueCoordinator.bridgeSelectionControllerDidRefreshBridges(self)
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        self.segueCoordinator.coordinate(segue:segue, sender:sender)
    }
}

private typealias PHBridgeSelectionViewControllerTableDatasource = PHBridgeSelectionViewController
extension PHBridgeSelectionViewControllerTableDatasource {
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.bridgeList.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell:UITableViewCell = tableView.dequeueReusableCell(withIdentifier:PHBridgeSelectionCellIdentifier) ?? UITableViewCell(style: .subtitle, reuseIdentifier: PHBridgeSelectionCellIdentifier)
        
        cell.setBridgeInfo(bridgeList[indexPath.row])
        return cell
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return NSLocalizedString("Please select a bridge to connect to", comment:"Header bridge selection view")
    }
}

private typealias PHBridgeSelectionViewControllerTableDelegate = PHBridgeSelectionViewController
extension PHBridgeSelectionViewControllerTableDelegate {
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        segueCoordinator.bridgeSelectionController(self, didSelectBridge:self.bridgeList[indexPath.row])
    }
}

private typealias PHBridgeSelectionViewControllerNavigable = PHBridgeSelectionViewController
extension PHBridgeSelectionViewControllerNavigable : NavigableController {
    var screenTitle: String {
        return NSLocalizedString("HueQuickStartApp", comment:"Title navigation light control screen")
    }
    
    var backButtonHidden: Bool {
        return true
    }
    
    var navigationBarHidden: Bool {
        return false
    }
    
    var rightNavigationButton: UIBarButtonItem {
        return UIBarButtonItem(barButtonSystemItem: .refresh, target: self, action: #selector(refreshButtonAction))
    }
}
