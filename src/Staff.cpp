#include "Staff.h"

Staff::Staff(const std::string& name, int skill, double wage)
    : name(name), skill(skill), wage(wage) {}

void Staff::train() {
    if (skill < 10) {
        ++skill;
    }
}

int Staff::getSkill() const {
    return skill;
}

double Staff::getWage() const {
    return wage;
}

const std::string& Staff::getName() const {
    return name;
}
