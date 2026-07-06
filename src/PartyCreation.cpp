#include "header/PartyCreation.h"
#include <iostream>

// Display the party creation menu
void PartyCreation::createParty() {
    std::string input;

    std::cout << "======================= Party Creation =======================\n";
    std::cout << "What are the first names of the five members in your party?\n";

    addPartyMemberLogic();
    std::cout << "===============================================================\n";

    std::cout << "Are these names correct? (yes/no): ";
    std::cin >> input;

    if (input == "no") {
        std::cout << "\nLet's start over.\n\n";
        p.clearMembers(); // Clear the current party members
        createParty(); // Restart the party creation process
    } else if (input == "yes") {
        std::cout << '\n\n';
    } else {
        std::cout << "Invalid input. Please enter 'yes' or 'no'.\n\n";
        createParty(); // Restart the party creation process
    }
}

// Handle the logic for adding a new party member
void PartyCreation::addPartyMemberLogic() {
    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 << ". ";

        std::cin >> input;

        p.addMember(input); // Add the member to the party
    }
}