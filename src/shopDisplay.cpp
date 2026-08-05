#include "header/shopDisplay.h"
#include <iostream>

// Space Creator Helper Function
std::string ShopDisplay::shopSpaceMaker(int lengthOfText) const {
    std::string spaceString;

    for (int i = 0; i < 28 - lengthOfText; ++i) { // Keeps the output to 28 and add how many spaces needed to make the message length 28
        spaceString += " ";
    }

    return spaceString;
}

// Displays the main shop menu
void ShopDisplay::displayMenu(const std::string& name, const std::vector<Items>& shop, double total, double balance) const {

    // Shop name header
    std::cout << "========================================" << "\n";
    std::cout << name << "\n";
    std::cout << "========================================" << "\n";

    // Creates list for all items and displays how much the player is spending on them
    for (int i = 0; i < shop.size(); ++i) {
        std::cout << i + 1 << ". " << shop[i].name << shopSpaceMaker(shop[i].name.length() + 3) << "$" << shop[i].price * shop[i].purchaseAmt << "\n";
    }


    // Balance check for players to allow for smart decisions
    std::cout << "Total Bill:" << shopSpaceMaker(11) << "$" << total << std::endl;
    std::cout << "Amount you have:" << shopSpaceMaker(16) << balance << "\n" << std::endl;
}

// Displays individual item purchasing screen
int ShopDisplay::displayItemMenu(const Items& target) const {
    std::cout << "======== Purchasing " << target.name << " ========" << "\n";
    std::cout << "Each of " << target.name << " costs $" << target.price << ".\n"; // Shows player how much the item costs
    std::cout << "How many " << target.name << " do you wish to purchase: ";
}

// Purchase limit message
void ShopDisplay::limitMessage(int limit, const std::string& name) const {
    std::cout << "You can only purchase " << limit << " of " << name << "\n" << "\n";
}

// Displays insufficient funds message
void ShopDisplay::insufficientFundsMessage() const {
    std::cout << "You do not have enough money to purchase this." << std::endl;
}

// Displays successful purchase message
void ShopDisplay::successfulPurchaseMessage(double total, double balance) const {
    std::cout << "======== Come back next time!!! ========" << std::endl;
    std::cout << "Total Spent: $" << total << std::endl;
    std::cout << "Current Balance: " << balance << std::endl;
    std::cout << "========================================" << std::endl;
}