#include "Contract.h"
#include "OilRig.h"

Contract::Contract(const std::string& client,
                   const std::string& description,
                   double reward,
                   int duration)
    : client(client),
      description(description),
      completed(false),
      reward(reward),
      daysRequired(duration),
      daysWorked(0) {}

void Contract::work(OilRig& rig) {
    if (completed) return;

    rig.operate();
    ++daysWorked;
    if (daysWorked >= daysRequired) {
        completed = true;
    }
}

bool Contract::isCompleted() const {
    return completed;
}

const std::string& Contract::getClient() const {
    return client;
}

double Contract::getReward() const {
    return reward;
}
