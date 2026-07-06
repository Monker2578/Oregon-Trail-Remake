#include "startscreen_shop_display.h"

// displays the starting prompt for the shop sequence of slides
void Startscreen_shop_display::initialSlide (std::ostream& out, int starting_amount) {
    out << "Before leaving Independence you" <<std::endl 
        <<"should buy equipment and supplies." << std::endl
        << "You have " << starting_amount
        << " in cash, but you don't have to "<< std::endl 
        <<"spend it all now." << std::endl;
    
    continueFooterPrompt(out); // calls helper function to print out footer text
}

// introduces game's shop
void Startscreen_shop_display::introduceShop(std::ostream& out) {
    out << "You can buy whatever you need at " << std::endl
        << "Matt's General Store." << std::endl;
    
    continueFooterPrompt(out); // calls helper function to print out footer text

}

// intro dialogue for shopkeeper
void Startscreen_shop_display::shopkeeperIntro (std::ostream& out) {
    out << "Hello, I'm Matt. So you're going " << std::endl
        << "to Oregon! I can fix you up with " << std::endl
        << "what you need:" << std::endl;
}

// shopkeeper farewell dialogue
void Startscreen_shop_display::shopkeeperFarewell (std::ostream& out) {
    out << "Well then, you're ready " << std::endl
        << "to start. Good luck!" << std::endl
        << "You have a long and " << std::endl
        << "difficult journey ahead " << std::endl
        << "of you." << std::endl;
    
    continueFooterPrompt(out); // calls helper function to print out footer text
}

// part one of things to buy
void Startscreen_shop_display::listPartOne(std::ostream& out) {
    shopkeeperIntro(out);  // calls shopkeeper intro dialogue
    
    out << "    - a team of oxen to pull" << std::endl
        << "      your wagon" << std::endl << std::endl
        << "    - clothing for both" << std::endl
        << "      summer and winter" << std::endl;

    continueFooterPrompt(out); // calls helper function to print out footer text

}

// part two of things to buy
void Startscreen_shop_display::listPartOne(std::ostream& out) {
    shopkeeperIntro(out);  // calls shopkeeper intro dialogue

    out << "    - plenty of food for the " << std::endl
        << "      trip" << std::endl << std::endl
        << "    - ammunition for your " << std::endl
        << "      riffles" << std::endl << std::endl
        << "    - spare parts for your " << std::endl
        << "      wagon" << std::endl;

    continueFooterPrompt(out); // calls helper function to print out footer text

}

// footer text
void Startscreen_shop_display::continueFooterPrompt (std::ostream& out) {
    out << "Press SPACE BAR to continue" << std::endl
        << "---------------------------" << std::endl;
}


