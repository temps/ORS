#ifndef STAFF_H
#define STAFF_H

#include <string>

class Staff {
public:
    Staff(const std::string& name, int skill, double wage);

    void train();
    int getSkill() const;
    double getWage() const;
    const std::string& getName() const;

private:
    std::string name;
    int skill; // 1..10
    double wage;
};

#endif // STAFF_H
