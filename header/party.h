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
        const Character& getAliveMember(size_t index) const;
        const Character& getDeceasedMember(size_t index) const;

        // Health and Condition System
        int getAverageHealth() const;
        Condition getAverageCondition(int averageHealth) const;

        // Health Management System
        void healMember(size_t index, int amt);
        void damageMember(size_t index, int amt);

        // Party Management System
        void addMember(const std::string& name);
        void killMember(size_t index);
};

#endif