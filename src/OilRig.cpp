#include "OilRig.h"

OilRig::OilRig(const std::string& identifier) : id(identifier) {}

void OilRig::addEquipment(std::unique_ptr<Equipment> item) {
    equipment.push_back(std::move(item));
}

void OilRig::assignStaff(std::shared_ptr<Staff> member) {
    crew.push_back(member);
}

void OilRig::operate() {
    for (auto& item : equipment) {
        item->degrade(5);
    }
}

void OilRig::performMaintenance() {
    for (auto& item : equipment) {
        item->maintain();
    }
}

double OilRig::produceOil() {
    if (equipment.empty() || crew.empty()) {
        return 0.0;
    }

    int conditionSum = 0;
    for (const auto& item : equipment) {
        conditionSum += item->getCondition();
    }
    double avgCondition = static_cast<double>(conditionSum) / equipment.size();

    int skillSum = 0;
    for (const auto& member : crew) {
        skillSum += member->getSkill();
    }
    double avgSkill = static_cast<double>(skillSum) / crew.size();

    double baseProduction = 100.0;
    return baseProduction * (avgCondition / 100.0) * (avgSkill / 10.0);
}

const std::string& OilRig::getId() const {
    return id;
}
