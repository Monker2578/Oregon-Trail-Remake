#ifndef SHOP_DISPLAY_H
#define SHOP_DISPLAY_H

#include "header/shop.h"
#include <string>

class ShopDisplay {
    private:
        // Space Text Generation
        std::string shopSpaceMaker(int lengthOfText) const;
    public:
        // Main Shop Menu Display
        void displayMenu(const std::string& name, const std::vector<Items>& shop, double total, double balance) const;

        // Individual Item Purchase Display
        int displayItemMenu(const Items& target) const;

        // Display item purchase limit message
        void limitMessage(int limit, const std::string& name) const;

        // Leave Shop Message Display
        void insufficientFundsMessage() const;
        void successfulPurchaseMessage(double total, double balance) const;
};

#endif