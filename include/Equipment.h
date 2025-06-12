#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

class Equipment {
public:
    explicit Equipment(const std::string& name);

    void degrade(int amount);
    void maintain();
    int getCondition() const;
    const std::string& getName() const;

private:
    std::string name;
    int condition; // percentage 0..100
};

#endif // EQUIPMENT_H
