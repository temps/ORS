#include "OilRig.h"

OilRig::OilRig(const std::string& identifier) : id(identifier) {}

void OilRig::addEquipment(std::unique_ptr<Equipment> item) {
    equipment.push_back(std::move(item));
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

const std::string& OilRig::getId() const {
    return id;
}
