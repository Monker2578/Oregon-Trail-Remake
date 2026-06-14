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
       displayMenu(name); // Displays the main shop menu


       // Displays the last portion of the shop (could be in displayMenu but fits better here given cin)
       int input;
       std::cout << "Which item would you like to change (press 0 to leave the store): ";


       // Different options
       if (!(std::cin >> input) || input < 0 || input > shop.size()) { // Checks for valid input
           std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           std::cout << "Please input a valid option!" << "\n" << "\n";
           continue; // Change so that it doesn't have to print the full menu again
       } else if (input == 0) {
           leaveShop(); // Leaves shop and confirm purchase
           break;
       } else {
           std::cout << "\n" << "\n";
           int amt = displayItemMenu(shop[input - 1].type); // Moves into individual item display screen
           purchaseAmtUpdate(shop[input - 1].type, amt); // Shopping cart gets updated correspondingly
       }
   }
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


// Displays the main shop menu
void Shop::displayMenu(const std::string& name) const {
   double total = totalPrice(); // Stores total price to reduce repetition


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
   std::cout << "Amount you have:" << shopSpaceMaker(16) << w.getItem(itemType::money) << "\n" << std::endl;
}


// Displays individual item purchasing screen
int Shop::displayItemMenu(itemType type) const {
   int input;
   const Items& target = itemFinder(type);


   std::cout << "======== Purchasing " << target.name << " ========" << "\n";
   std::cout << "Each of " << target.name << " costs $" << target.price << ".\n"; // Shows player how much the item costs
   std::cout << "How many " << target.name << " do you wish to purchase: ";


   // Checks if the input is valid (prevents inputs such as characters)
   if (!(std::cin >> input)) {
       std::cin.clear(); // Clears the error state
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores the invalid input
       return 0;
   }


   std::cout << "========================================" << "\n" << "\n";


   if (input > target.purchaseLimit) {
       limitMessage(target.purchaseLimit, target.name);
       return 0;
   } else {
       return input;
   }
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




// Purchase limit message
void Shop::limitMessage(int limit, const std::string& name) const {
   std::cout << "You can only purchase " << limit << " of " << name << "\n" << "\n";
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
       std::cout << "You do not have enough money to purchase this." << std::endl;


       for (auto& item : shop) { // Resets the purchaseAmt history for all items in the shop inventory
           item.purchaseAmt = 0;
       }


       return;
   }


   // Prints if balance > total
   std::cout << "======== Come back next time!!! ========" << std::endl;
   std::cout << "Total Spent: $" << total << std::endl;


   // Adds the amounts of each item purchased to the wagon inventory
   for (auto& item : shop) {
       w.gainItem(item.type, item.purchaseAmt);
   }
   w.useItem(itemType::money, total); // Changes money to reflect on how much the player spent


   // Resets the purchaseAmt history for all items in the shop inventory
   for (auto& item : shop) {
       item.purchaseAmt = 0;
   }


   // Finish printing the leaving message with the player's leftover balance
   std::cout << "Current Balance: " << w.getItem(itemType::money) << std::endl;
   std::cout << "========================================" << std::endl;
}


// Space Creator Helper Function
std::string Shop::shopSpaceMaker(int lengthOfText) const {
   std::string spaceString;


   for (int i = 0; i < 28 - lengthOfText; ++i) { // Keeps the output to 28 and add how many spaces needed to make the message length 28
       spaceString += " ";
   }


   return spaceString;
}