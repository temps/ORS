#ifndef OILRIG_H
#define OILRIG_H

#include <memory>
#include <string>
#include <vector>
#include "Equipment.h"
#include "Staff.h"

class OilRig {
public:
    explicit OilRig(const std::string& identifier);

    void addEquipment(std::unique_ptr<Equipment> item);
    void assignStaff(std::shared_ptr<Staff> member);
    void operate();
    void performMaintenance();
    double produceOil();
    const std::string& getId() const;

private:
    std::string id;
    std::vector<std::unique_ptr<Equipment>> equipment;
    std::vector<std::shared_ptr<Staff>> crew;
};

#endif // OILRIG_H
