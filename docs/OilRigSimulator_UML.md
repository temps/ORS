# Oil Rig Simulator UML Diagram

This document presents an ASCII‑style UML diagram and sample code for the main objects of the Oil Rig Simulator game design.

## UML Diagram

```
+-----------+       manages      +---------+       executes      +-----------+
|  Company  |------------------>| OilRig  |-------------------->| Contract  |
+-----------+ owns / operates   +---------+       requires      +-----------+
       |                           | 1..*                     1..*
       | maintains               uses
       |                           v
       |                        +-----------+
       +----------------------->| Equipment |
                                +-----------+

                             +--------+
                             | Staff  |
                             +--------+

+---------+
|  Market |
+---------+
     ^
     | influences
     |
+-----------+
|  Company  |
+-----------+
```

* `Company` manages multiple `OilRig` instances and holds `Contract`s.
* `OilRig` uses multiple pieces of `Equipment`.
* `Contract` defines work to be performed on an oil rig.
* `Market` represents the global oil market influenced by the player's actions.

## Key Objects and Sample Code

### Company
```cpp
class Company {
public:
    explicit Company(const std::string& name) : name(name) {}

    void acquireRig(OilRig* rig) {
        oilRigs.push_back(rig);
    }

    void signContract(const Contract& contract) {
        contracts.push_back(contract);
    }

private:
    std::string name;
    std::vector<OilRig*> oilRigs;
    std::vector<Contract> contracts;
};
```

### OilRig
```cpp
class OilRig {
public:
    explicit OilRig(const std::string& identifier) : id(identifier) {}

    void addEquipment(Equipment* item) {
        equipment.push_back(item);
    }

    void performMaintenance() {
        for (auto& item : equipment) {
            item->maintain();
        }
    }

private:
    std::string id;
    std::vector<Equipment*> equipment;
};
```

### Equipment
```cpp
class Equipment {
public:
    explicit Equipment(const std::string& name)
        : name(name), condition(100) {}

    void maintain() {
        if (condition < 100) {
            condition = 100;
        }
    }

private:
    std::string name;
    int condition; // percentage
};
```

### Contract
```cpp
class Contract {
public:
    Contract(const std::string& client, const std::string& description, double reward)
        : client(client), description(description), completed(false), reward(reward) {}

    void execute(OilRig& rig) {
        // logic for contract execution
        completed = true;
    }

private:
    std::string client;
    std::string description;
    bool completed;
    double reward;
};
```

### Staff
```cpp
class Staff {
public:
    Staff(const std::string& name, int skill, double wage)
        : name(name), skill(skill), wage(wage) {}

    void train() { if (skill < 10) ++skill; }

private:
    std::string name;
    int skill;
    double wage;
};
```

### Market
```cpp
class Market {
public:
    Market() : oilPrice(70.0) {}

    void updatePrice(double demand, double supply) {
        // simplified example
        oilPrice += 0.1 * (demand - supply);
    }

private:
    double oilPrice;
};
```

These examples illustrate the basic structure and relationships between the main objects in Oil Rig Simulator.
