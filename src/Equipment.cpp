#include "Equipment.h"

Equipment::Equipment(const std::string& name) : name(name), condition(100) {}

void Equipment::degrade(int amount) {
    condition -= amount;
    if (condition < 0) condition = 0;
}

void Equipment::maintain() {
    if (condition < 100) condition = 100;
}

int Equipment::getCondition() const {
    return condition;
}

const std::string& Equipment::getName() const {
    return name;
}
