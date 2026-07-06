#include "header/ProfessionSelection.h"
#include <iostream>

// Display the profession selection menu
void ProfessionSelection::selectProfession() {
    std::cout << "Many kinds of people made the trip to Oregon.\n\n";
    std::cout << "You may:\n";
    std::cout << "1. Be a banker from Boston\n";
    std::cout << "2. Be a carpenter from Ohio\n";
    std::cout << "3. Be a farmer from Illinois\n";
    std::cout << "4. Learn about the differences between the professions\n\n";
    std::cout << "Enter the number of your choice: ";

    int input;
    std::cin >> input;
    return selectProfessionLogic(input);
}

// Handle the logic for the selected profession
void ProfessionSelection::selectProfessionLogic(int choice) {
    switch (choice) {
        case 1:
            w.professionBuff(Profession::Banker);
            break;
        case 2:
            w.professionBuff(Profession::Carpenter);
            break;
        case 3:
            w.professionBuff(Profession::Farmer);
            break;
        case 4:
            professionDifference();
        default: // Handle invalid input
            std::cout << "Invalid choice, please select again.\n";
            return selectProfessionDisplay();
    }
}

// Display the differences between professions
void ProfessionSelection::professionDifference() const {
    std::cout << "================== Profession Differences ==================\n";
    std::cout << "Bankers are wealthy and well-educated.\n";
    std::cout << "Carpenters are skilled with tools and can build useful items.\n";
    std::cout << "Farmers are experienced with the land and can find food.\n";
    std::cout << "=============================================================\n";
    std::cout << "Press 0 to return to the profession selection menu: ";

    int input;
    std::cin >> input;

    // Wait for the user to press 0 to return to the profession selection menu
    while (input != 0) {
        std::cout << "Invalid input. Please press 0 to return: ";
        std::cin >> input;
    }
}