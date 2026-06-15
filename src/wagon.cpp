#include "header/wagon.h"
#include <iostream>
#include <stdexcept>


// Constructor
Wagon::Wagon() {
   wagon = Inventory();
}


// Adds corresponding buffs to the profession the player picked
void Wagon::professionBuff(Profession profession) {
   switch (profession) {
       case Profession::banker:
           wagon.moneyAmt += 1600; // Adds money
           break;
       case Profession::carpenter:
           wagon.axleAmt += 1; // Adds axle
           wagon.wheelAmt += 1; // Adds wheel
           wagon.tongueAmt += 1; // Adds tongue
           wagon.moneyAmt += 800; // Reduced money
           break;
       case Profession::farmer:
           wagon.foodAmt += 500; // Adds food
           wagon.oxenAmt += 2; // Adds oxen
           wagon.moneyAmt += 400; // Reduced money
           break;
   }
}


// Inventory Checking System (Whole)
void Wagon::getInv() const {
   std::cout << "========== Wagon Inventory ==========" << "\n"
               << "Oxen: " << wagon.oxenAmt << "\n"
               << "Sets of Clothing: " << wagon.clothingAmt << "\n"
               << "Bullets: " << wagon.ammunitionAmt << "\n"
               << "Wagon Wheels: " << wagon.wheelAmt << "\n"
               << "Wagon Axles: " << wagon.axleAmt << "\n"
               << "Wagon Tongues: " << wagon.tongueAmt << "\n"
               << "Pounds of Food: " << wagon.foodAmt << "\n"
               << "Money Left: " << wagon.moneyAmt << "\n"
               << "=====================================" << std::endl;
}


// Inventory Checking System (Individual)
double Wagon::getItem(itemType type) const {
   switch (type) {
       case itemType::food:
           return wagon.foodAmt;
       case itemType::money:
           return wagon.moneyAmt;
       case itemType::ammunition:
           return wagon.ammunitionAmt;
       case itemType::clothing:
           return wagon.clothingAmt;
       case itemType::axle:
           return wagon.axleAmt;
       case itemType::wheel:
           return wagon.wheelAmt;
       case itemType::tongue:
           return wagon.tongueAmt;
       case itemType::oxen:
           return wagon.oxenAmt;
       default: // Throws exception if user inputs an item type that is not within the itemType class
           throw std::invalid_argument("Invalid item type");
   }
}


// Inventory Use System
bool Wagon::useItem(itemType type, double amt) {
   if (amt < 0) { return false; } // Prevents users from using non-positive amounts


   switch (type) {
       case itemType::food:
           if (wagon.foodAmt < amt) { return false; } // If user does not have enough food
           wagon.foodAmt -= amt;
           return true;
       case itemType::money:
           if (wagon.moneyAmt < amt) { return false; } // If user does not have enough money
           wagon.moneyAmt -= amt;
           return true;
       case itemType::ammunition:
           if (wagon.ammunitionAmt < amt) { return false; } // If user does not have enough ammunition
           wagon.ammunitionAmt -= amt;
           return true;
       case itemType::clothing:
           if (wagon.clothingAmt < amt) { return false; } // If user does not have enough clothing
           wagon.clothingAmt -= amt;
           return true;
       case itemType::axle:
           if (wagon.axleAmt < amt) { return false; } // If user does not have enough wagon axles
           wagon.axleAmt -= amt;
           return true;
       case itemType::wheel:
           if (wagon.wheelAmt < amt) { return false; } // If user does not have enough wagon wheels
           wagon.wheelAmt -= amt;
           return true;
       case itemType::tongue:
           if (wagon.tongueAmt < amt) { return false; } // If user does not have enough wagon tongues
           wagon.tongueAmt -= amt;
           return true;
       case itemType::oxen:
           if (wagon.oxenAmt < amt) { return false; } // If user does not have enough oxens
           wagon.oxenAmt -= amt;
           return true;
       default: // Throws exception if user inputs an item type that is not within the itemType class
           throw std::invalid_argument("Invalid item type");
   }
}


// Inventory Gain System
bool Wagon::gainItem(itemType type, double amt) {
   if (amt < 0) { return false; } // Prevents users from adding non-positive amounts
  
   switch (type) {
       case itemType::food:
           if (wagon.foodAmt >= 2000) { return false; } // If user already has or over 2000 lbs of food
           if (wagon.foodAmt + amt >= 2000) { // If current food + addition goes past 2000
               wagon.foodAmt = 2000;
           } else { // If current food + addition is still less than 2000
               wagon.foodAmt += amt;
           }
           return true;
       case itemType::money:
           wagon.moneyAmt += amt;
           return true;
       case itemType::ammunition:
           wagon.ammunitionAmt += amt;
           return true;
       case itemType::clothing:
           wagon.clothingAmt += amt;
           return true;
       case itemType::axle:
           wagon.axleAmt += amt;
           return true;
       case itemType::wheel:
           wagon.wheelAmt += amt;
           return true;
       case itemType::tongue:
           wagon.tongueAmt += amt;
           return true;
       case itemType::oxen:
           wagon.oxenAmt += amt;
           return true;
       default: // Throws exception if user inputs an item type that is not within the itemType class
           throw std::invalid_argument("Invalid item type");
   }
}