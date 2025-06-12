#include "Company.h"

Company::Company(const std::string& name) : name(name), cash(10000.0), reputation(0) {}

void Company::acquireRig(std::unique_ptr<OilRig> rig) {
    oilRigs.push_back(std::move(rig));
}

void Company::signContract(const Contract& contract) {
    contracts.push_back(contract);
}

void Company::hireStaff(std::shared_ptr<Staff> member) {
    employees.push_back(member);
    if (!oilRigs.empty()) {
        oilRigs.front()->assignStaff(member);
    }
}

void Company::operateRigs() {
    for (auto& rig : oilRigs) {
        rig->operate();
        double produced = rig->produceOil();
        cash += produced * market.getPrice();
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
            contract.work(*oilRigs.front());
            if (contract.isCompleted()) {
                cash += contract.getReward();
                reputation += 1;
            }
        }
    }
}

void Company::payWages() {
    for (const auto& e : employees) {
        cash -= e->getWage();
    }
}

void Company::nextDay() {
    operateRigs();
    executeContracts();
    performMaintenance();
    payWages();
}

Market& Company::getMarket() {
    return market;
}

double Company::getCash() const {
    return cash;
}

int Company::getReputation() const {
    return reputation;
}
