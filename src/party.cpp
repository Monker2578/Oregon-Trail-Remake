#include "header/party.h"

// Constructor
Party::Party() {}


// Getters
int Party::getPartySize() const {
    return members.size();
}

Character& Party::getMember(size_t index) {
    if (index >= members.size()) {
        throw std::out_of_range("Invalid Index"); // Throw error if the index is out of bound
    }
    return members.at(index);
}

int Party::getAverageHealth() const {
    if (members.empty()) { return 0; } // Return 0 if there are no members in the party

    int totalHealth = 0;
    for (const auto& member : members) {
        totalHealth += member.getHealth();
    }
    return totalHealth / members.size();
}

Condition Party::getAverageCondition(int averageHealth) const {
    if (averageHealth >= 80) { return Condition::execellent; }
    else if (averageHealth >= 60) { return Condition::good; }
    else if (averageHealth >= 40) { return Condition::fair; }
    else if (averageHealth >= 20) { return Condition::poor; }
    else { return Condition::critical; }
}

// Party Management System
void Party::addMember(const std::string& name) {
    members.push_back(Character(name));
}

void Party::removeMember(size_t index) {
    if (index >= members.size()) {
        throw std::out_of_range("Invalid Index"); // Throw error if the index is out of bound
    }
    members.erase(members.begin() + index);
}