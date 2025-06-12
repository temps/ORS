#ifndef COMPANY_H
#define COMPANY_H

#include <memory>
#include <string>
#include <vector>
#include "OilRig.h"
#include "Contract.h"
#include "Market.h"

class Company {
public:
    explicit Company(const std::string& name);

    void acquireRig(std::unique_ptr<OilRig> rig);
    void signContract(const Contract& contract);
    void operate();
    void performMaintenance();
    void executeContracts();
    Market& getMarket();

private:
    std::string name;
    std::vector<std::unique_ptr<OilRig>> oilRigs;
    std::vector<Contract> contracts;
    Market market;
};

#endif // COMPANY_H
