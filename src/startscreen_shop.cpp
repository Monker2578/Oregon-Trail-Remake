#include "startscreen_shop.h"
#include "startscreen_shop_display.h"
#include <iostream>

Startscreen_shop::Startscreen_shop (std::ostream& out, int starting_amount,std::istream& in) {
    currSlide = 0;  // keeps track of current slide/dialogue

    // sets up display class
    Startscreen_shop_display display;
    display.initialSlide(out, starting_amount);
    continueInput(out, in, display);  // logic for shop sequence
}

void Startscreen_shop::next_slide(std::ostream& out, std::istream& in, Startscreen_shop_display& display) {

    // keeps track of sequence of slides
    switch (currSlide) {
        case 0:
            currSlide++;
            display.introduceShop(out);
            break;
        case 1:
            currSlide++;
            display.listPartOne(out);
            break;
        case 2:
            currSlide++;
            display.listPartTwo(out);
            break;
        case 3:
            currSlide++;
            display.shopkeeperFarewell(out);
            break;
        default:
            return;
    }
}

void Startscreen_shop::continueInput (std::ostream& out, std::istream& in, Startscreen_shop_display& display) {

    // logic to validate input to move forward to next slide
    char input;
    do {
        in.get(input);
    } while (input != ' ');
    next_slide(out, in, display);
}



