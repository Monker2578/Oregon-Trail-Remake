#ifndef PARTY_H
#define PARTY_H

#include <vector>
#include "header/character.h"

class Party {
    private:
        std::vector<Character> aliveMembers;
        std::vector<Character> deceasedMembers;
    public:
        // Constructor
        Party();

        // Parties Size System
        int aliveSize() const;
        int deceasedSize() const;

        // Member Access System
        const Character& getMember(size_t index) const;
        const Character& getDeceasedMember(size_t index) const;

        // Health and Condition System
        int getAverageHealth() const;
        Condition getAverageCondition(int averageHealth) const;

        // Party Management System
        void addMember(const std::string& name);
        void removeMember(size_t index);
};

#endif