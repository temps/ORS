#include "Company.h"

Company::Company(const std::string& name) : name(name) {}

void Company::acquireRig(std::unique_ptr<OilRig> rig) {
    oilRigs.push_back(std::move(rig));
}

void Company::signContract(const Contract& contract) {
    contracts.push_back(contract);
}

void Company::operate() {
    for (auto& rig : oilRigs) {
        rig->operate();
    }
}

void Company::performMaintenance() {
    for (auto& rig : oilRigs) {
        rig->performMaintenance();
    }
}

void Company::executeContracts() {
    for (auto& contract : contracts) {
        if (!contract.isCompleted() && !oilRigs.empty()) {
            contract.execute(*oilRigs.front());
        }
    }
}

Market& Company::getMarket() {
    return market;
}
