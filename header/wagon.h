#ifndef WAGON_H
#define WAGON_H


#include <vector>

struct Inventory { // Wagon inventory data
   int foodAmt = 0;
   double moneyAmt = 0;
   int ammunitionAmt = 0;
   int clothingAmt = 0;


   int axleAmt = 0;
   int wheelAmt = 0;
   int tongueAmt = 0;


   int oxenAmt = 0;
};


enum class Profession {banker, carpenter, farmer};


enum class itemType {food, money, ammunition, clothing, axle, wheel, tongue, oxen};


class Wagon {
   private:
       Inventory wagon;
   public:
       // Constructor
       Wagon();


       // Profession Buff System
       void professionBuff(Profession profession);
      
       // Inventory Checking System (Whole)
       void getInv() const;


       // Inventory Checking System (Individual)
       double getItem(itemType type) const;


       // Inventory Use System
       bool useItem(itemType type, double amt);


       // Inventory Gain System
       bool gainItem(itemType type, double amt);
};


#endif