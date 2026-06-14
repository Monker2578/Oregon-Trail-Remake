#ifndef PARTY_H
#define PARTY_H

#include <vector>
#include "header/character.h"

class Party {
    private:
        std::vector<Character> members;
    public:
        // Constructor
        Party();

        // Getters
        int getPartySize() const;
        Character& getMember(size_t index);
        int getAverageHealth() const;
        Condition getAverageCondition(int averageHealth) const;

        // Party Management System
        void addMember(const std::string& name);
        void removeMember(size_t index);
};

#endif