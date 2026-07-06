#ifndef PARTY_CREATION_H
#define PARTY_CREATION_H

#include "header/party.h"

class PartyCreation {
    public:
        Party& p; // Reference to the Party object to manage party members

        // Constructor to initialize the PartyCreation with a reference to a Party object
        PartyCreation(Party& p) : p(p) {}

        // Display the party creation menu
        void createParty();

        // Handle the logic for adding a new party member
        void addPartyMemberLogic();
};

#endif