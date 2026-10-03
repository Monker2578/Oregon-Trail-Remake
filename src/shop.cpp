#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include "shop.h"

// Constructor
Shop::Shop(Wagon& w) : w(w) {
    shop = { {"Oxen", itemType::oxen, 20, 20},
        {"Food", itemType::food, 0.2, 2000},
        {"Ammunition", itemType::ammunition, 0.1, 1000},
        {"Clothing", itemType::clothing, 10, 40},
        {"Spare Parts - Axle", itemType::axle, 10, 3},
        {"Spare Parts - Wheel", itemType::wheel, 10, 3},
        {"Spare Parts - Tongue", itemType::tongue, 10, 3} };
}

// Runs the shop system
void Shop::runShop(const std::string& name) {
    while (true) { // Stops only after the user exit the shop

        d.displayMenu(name, shop, totalPrice(), w.getItem(itemType::money)); // Displays the main shop menu

        // Displays the last portion of the shop (could be in displayMenu but fits better here given cin)
        int input;
        std::cout << "Which item would you like to edit (press 0 to leave the store): ";

        // Different options
        if (!(std::cin >> input) || input < 0 || input > static_cast<int>(shop.size())) { // Checks for valid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please input a valid option!" << "\n" << "\n";
            continue; // Change so that it doesn't have to print the full menu again
        } else if (input == 0) {
            leaveShop(); // Leaves shop and confirm purchase
            break;
        } else {
            std::cout << "\n" << "\n";

            // Displays the individual item purchasing screen
            const Items& target = shop[input - 1];
            d.displayItemMenu(target);

            int amt;
            // Checks if the input is valid (prevents inputs such as characters)
            if (!(std::cin >> input)) {
                std::cin.clear(); // Clears the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the invalid input
                amt = 0;
            }

            std::cout << "========================================" << "\n" << "\n";

            // Checks if the desired amount exceeds the item purchase limit
            if (amt > target.purchaseLimit) {
                d.limitMessage(target.purchaseLimit, target.name);
                amt = 0;
            }

            purchaseAmtUpdate(target.type, amt); // Shopping cart gets updated correspondingly
        }
    }
}

// Display total shopping cart price
double Shop::totalPrice() const {
    double total = 0;

    for (const auto& item : shop) {
        total += item.price * item.purchaseAmt; // Adds to the total amount
    }

    return total;
}

// Needs comments starting from here will add later
void Shop::purchaseAmtUpdate(itemType type, int amt) {
    if (amt < 0) { return; } // Checks for valid amt input
    for (auto& item : shop) {
        if (item.type == type) {
            item.purchaseAmt = amt; // Changes purchaseAmt if only the type matches
            return;
        }
    }
}

// Final Checkout System
void Shop::leaveShop() {
    double total = totalPrice(); // Calculates total price to prevent repetition

    // Checks if the shopping cart price is over the player's balance
    if (w.getItem(itemType::money) < total) {
        // Prints Unsuccessful purchase attempt
        d.insufficientFundsMessage();

        for (auto& item : shop) { // Resets the purchaseAmt history for all items in the shop inventory
            item.purchaseAmt = 0;
        }

        return;
    }

    // Adds the amounts of each item purchased to the wagon inventory
    for (auto& item : shop) {
        w.gainItem(item.type, item.purchaseAmt);
    }
    w.useItem(itemType::money, total); // Changes money to reflect on how much the player spent

    // Resets the purchaseAmt history for all items in the shop inventory
    for (auto& item : shop) {
        item.purchaseAmt = 0;
    }

    // Display successful purchase
    d.successfulPurchaseMessage(total, w.getItem(itemType::money));
}

// Item Finder System
const Items& Shop::itemFinder(itemType type) const {
    for (const auto& item : shop) {
        if (item.type == type) { // Validates if the type is the same as the parameter
            return item;
        }
    }
    throw std::invalid_argument("Invalid Input"); // Throws error if no item is found with the same type as the parameter
}


// ===== Again, mainly for testing :) =====


// Returns the specific item price
double Shop::displayItemPrice(itemType type) const {
    return itemFinder(type).price;
}

// Returns the specific item purchase limit
int Shop::displayItemLimit(itemType type) const {
    return itemFinder(type).purchaseLimit;
}