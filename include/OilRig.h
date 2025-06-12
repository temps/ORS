#ifndef OILRIG_H
#define OILRIG_H

#include <memory>
#include <string>
#include <vector>
#include "Equipment.h"

class OilRig {
public:
    explicit OilRig(const std::string& identifier);

    void addEquipment(std::unique_ptr<Equipment> item);
    void operate();
    void performMaintenance();
    const std::string& getId() const;

private:
    std::string id;
    std::vector<std::unique_ptr<Equipment>> equipment;
};

#endif // OILRIG_H
