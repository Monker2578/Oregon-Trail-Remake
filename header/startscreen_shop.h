#ifndef STARTSCREEN_SHOP_H
#define STARTSCREEN_SHOP_H

#include <iostream>
class Startscreen_shop {
    public:
        Startscreen_shop (std::ostream& , int , std::istream& );
        

    private:
        void next_slide(std::ostream& , std::istream& , Startscreen_shop_display& );
        void continueInput (std::ostream& out, std::istream& in, Startscreen_shop_display& );
        int currSlide;

};
#endif