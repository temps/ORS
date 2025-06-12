#include <iostream>
#include <memory>
#include "Company.h"
#include "Staff.h"

int main() {
    Company company("OrsOps");

    auto rig = std::make_unique<OilRig>("Rig-1");
    rig->addEquipment(std::make_unique<Equipment>("Drill"));
    rig->addEquipment(std::make_unique<Equipment>("Pump"));
    company.acquireRig(std::move(rig));

    auto staff1 = std::make_shared<Staff>("Alice", 5, 1000.0);
    auto staff2 = std::make_shared<Staff>("Bob", 6, 1200.0);
    company.hireStaff(staff1);
    company.hireStaff(staff2);

    Contract c1("ClientA", "Initial drilling", 5000.0);
    company.signContract(c1);

    for (int day = 0; day < 3; ++day) {
        std::cout << "--- Day " << day + 1 << " ---" << std::endl;
        company.executeContracts();
        company.operate();
        company.performMaintenance();
        company.getMarket().updatePrice(5.0 + day, 3.0);
        std::cout << "Cash: " << company.getCash()
                  << " Reputation: " << company.getReputation()
                  << " Price: " << company.getMarket().getPrice() << std::endl;
    }

    return 0;
}
