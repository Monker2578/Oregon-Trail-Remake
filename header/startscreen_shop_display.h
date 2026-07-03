#ifndef STARTSCREEN_SHOP_DISPLAY_H
#define STARTSCREEN_SHOP_DISPLAY_H
#include <iostream>
class Startscreen_shop_display {
    public:
        Startscreen_shop_display() = default;
        void initialSlide (std::ostream& , int );
        void introduceShop (std::ostream& );
        void listPartOne(std::ostream& );
        void listPartTwo(std::ostream& );
        void shopkeeperFarewell (std::ostream& );

    private:
        void continueFooterPrompt (std::ostream& );
        void shopkeeperIntro (std::ostream& );

};
#endif
