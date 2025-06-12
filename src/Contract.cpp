#include "Contract.h"
#include "OilRig.h"

Contract::Contract(const std::string& client, const std::string& description)
    : client(client), description(description), completed(false) {}

void Contract::execute(OilRig& rig) {
    rig.operate();
    completed = true;
}

bool Contract::isCompleted() const {
    return completed;
}

const std::string& Contract::getClient() const {
    return client;
}
