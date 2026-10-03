#include "header/party.h"
#include <utility>
#include <stdexcept>
 
// Constructor
Party::Party() {}
 

// Gets an alive member at the specified index
const Character& Party::getAliveMember(size_t index) const {
    if (index >= aliveMembers.size()) {
        throw std::out_of_range("Index out of range"); // Throw an exception if the index is out of range
    }
    return aliveMembers.at(index);
}

// Gets a deceased member at the specified index
const Character& Party::getDeceasedMember(size_t index) const {
    if (index >= deceasedMembers.size()) {
        throw std::out_of_range("Index out of range"); // Throw an exception if the index is out of range
    }
    return deceasedMembers.at(index);
}

// Get the number of alive members
int Party::aliveSize() const {
    return aliveMembers.size();
}
 
// Get the number of deceased members
int Party::deceasedSize() const {
    return deceasedMembers.size();
}

// Heals a member at the specified index
void Party::healMember(size_t index, int amt) {
    if (index >= aliveMembers.size()) {
        throw std::out_of_range("Index out of range"); // Throw an exception if the index is out of range
    }
    aliveMembers.at(index).heal(amt);
}

// Damages a member at the specified index
void Party::damageMember(size_t index, int amt) {
    if (index >= aliveMembers.size()) {
        throw std::out_of_range("Index out of range"); // Throw an exception if the index is out of range
    }
    aliveMembers.at(index).takeDamage(amt);
}

// Adds a member to the party
void Party::addMember(const std::string& name) {
    aliveMembers.emplace_back(name); // Used emplace_back to improve efficiency by constructing the Character in place
}
 
// Kills a member at the specified index
void Party::killMember(size_t index) {
    if (index >= aliveMembers.size()) {
        throw std::out_of_range("Index out of range"); // Throw an exception if the index is out of range
    }
 
    deceasedMembers.push_back(std::move(aliveMembers.at(index)));
    aliveMembers.erase(aliveMembers.begin() + index);
}
 
// Get the average health of alive members
int Party::getAverageHealth() const {
    if (aliveMembers.empty()) { return 0; } // Avoid division by zero
 
    int totalHealth = 0;
    for (const auto& member : aliveMembers) {
        totalHealth += member.getHealth();
    }
 
    return totalHealth / aliveMembers.size();
}
 
// Get the average condition of alive members based on average health
Condition Party::getAverageCondition(int averageHealth) const {
    if (averageHealth >= 80) { return Condition::excellent;
    } else if (averageHealth >= 60) { return Condition::good;
    } else if (averageHealth >= 40) { return Condition::fair;
    } else if (averageHealth >= 20) { return Condition::poor;
    } else { return Condition::critical; }
}