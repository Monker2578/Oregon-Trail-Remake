#ifndef SHOP_H
#define SHOP_H


#include <string>
#include "header/wagon.h"


struct Items { // Shop Inventory Data
   std::string name;
   itemType type;
   double price;
   int purchaseLimit;
   int purchaseAmt = 0;
};


class Shop {
   private:
       // Vector of the seven items available in the shop
       std::vector<Items> shop;


       // Reference to the wagon inventory
       Wagon& w;



       // Helper Functions:


       // Main Shop Menu Display
       void displayMenu(const std::string& name) const;


       // Individual Item Purchase Display
       int displayItemMenu(itemType type) const;


       // Display item purchase limit message
       void limitMessage(int limit, const std::string& name) const;


       // Display Total Cart Price
       double totalPrice() const;


       // Updates purchaseAmt in shop inventory
       void purchaseAmtUpdate(itemType type, int amt);


       // Final Checkout
       void leaveShop();


       // Item Finder
       const Items& itemFinder(itemType type) const;


       // Space Text Generation
       std::string shopSpaceMaker(int lengthOfText) const;


   public:
       // Constructor
       Shop(Wagon& w);


       // Run Shop System
       void runShop(const std::string& name);




       // ===== Mainly for testing :) =====


       // Display Individual Item Price
       double displayItemPrice(itemType type) const;


       // Display Individual Item Purchase Limit
       int displayItemLimit(itemType type) const;
};


#endif