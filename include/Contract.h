#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
class OilRig; // forward declaration

class Contract {
public:
    Contract(const std::string& client, const std::string& description);

    void execute(OilRig& rig);
    bool isCompleted() const;
    const std::string& getClient() const;

private:
    std::string client;
    std::string description;
    bool completed;
};

#endif // CONTRACT_H
