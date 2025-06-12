#ifndef COMPANY_H
#define COMPANY_H

#include <memory>
#include <string>
#include <vector>
#include "OilRig.h"
#include "Contract.h"
#include "Market.h"
#include "Staff.h"

class Company {
public:
    explicit Company(const std::string& name);

    void acquireRig(std::unique_ptr<OilRig> rig);
    void signContract(const Contract& contract);
    void hireStaff(std::shared_ptr<Staff> member);
    void operate();
    void performMaintenance();
    void executeContracts();
    Market& getMarket();
    double getCash() const;
    int getReputation() const;

private:
    std::string name;
    std::vector<std::unique_ptr<OilRig>> oilRigs;
    std::vector<Contract> contracts;
    std::vector<std::shared_ptr<Staff>> employees;
    double cash;
    int reputation;
    Market market;
};

#endif // COMPANY_H
