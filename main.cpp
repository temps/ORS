#include <iostream>
#include "Company.h"

int main() {
    Company company("OrsOps");

    auto rig = std::make_unique<OilRig>("Rig-1");
    rig->addEquipment(std::make_unique<Equipment>("Drill"));
    rig->addEquipment(std::make_unique<Equipment>("Pump"));
    company.acquireRig(std::move(rig));

    Contract c1("ClientA", "Initial drilling");
    company.signContract(c1);

    std::cout << "Executing contracts..." << std::endl;
    company.executeContracts();
    std::cout << "Operation done. Performing maintenance..." << std::endl;
    company.performMaintenance();

    company.getMarket().updatePrice(5.0, 3.0);
    std::cout << "Current oil price: " << company.getMarket().getPrice() << std::endl;

    return 0;
}
