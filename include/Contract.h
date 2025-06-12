#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
class OilRig; // forward declaration

class Contract {
public:
    Contract(const std::string& client, const std::string& description, double reward);

    void execute(OilRig& rig);
    bool isCompleted() const;
    const std::string& getClient() const;
    double getReward() const;

private:
    std::string client;
    std::string description;
    bool completed;
    double reward;
};

#endif // CONTRACT_H
