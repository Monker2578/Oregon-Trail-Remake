#include "monthSelection.h"
MonthSelection::MonthSelection(std::ostream& out, std::istream& in) {
    // sets initial date
    gameTime.year = 1848;
    gameTime.day = 1;

    // calls display class to prompt user to choose month
    MonthSelectionDisplay display;
    display.monthSelectionPompt(out);

    // handels input selection
    inputSelection(display, in, out);
    
}

// returns start game date in date struct
Date MonthSelection::getStartDate() const {
    return gameTime;
}

// Private helper functions 

void MonthSelection::inputSelection (MonthSelectionDisplay& display, std::istream& in, std::ostream& out) {

    // validates input: valid input range (1-6)
    int input;
    do {
        in >> input;
    } while (input < 0 && input > 6);

    switch (input) {
        case 1:
            gameTime.month = 3;  // user option March
            break;
        case 2:
            gameTime.month = 4;  // user option April
            break;
        case 3:
            gameTime.month = 5;  // user option May
            break;
        case 4:
            gameTime.month = 6;  // user option June
            break;
        case 5:
            gameTime.month = 7;  // user option July
            break;
        case 6:
            adviceSelection(out, in, display);  // user option "ask for advice"
            break;

    }
}

void MonthSelection::adviceSelection(std::ostream& out, std::istream& in, MonthSelectionDisplay& display) {

    // calls display function to display advice slide
    display.adviceOption(out);

    // validates input "space bar"
    char input;
    do {
        in >> input;
    } while (input != ' ');

    // calls month selection prompt and month selection input logic
    display.monthSelectionPompt(out);
    inputSelection(display,in,out);
}


