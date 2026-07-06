#include "monthSelection.h"

MonthSelection::MonthSelection(std::ostream& out, std::istream& in) {

    
    // calls display class to prompt user to choose month
    MonthSelectionDisplay display;
    display.monthSelectionPompt(out);

    // handels input selection
    inputSelection(display, in, out);
    
}

// returns start game date in date struct
const Date& MonthSelection::getStartDate() const {
    return gameTime;
}

// Private helper functions 
void MonthSelection::inputSelection (MonthSelectionDisplay& display, std::istream& in, std::ostream& out) {

    // validates input: valid input range (1-6)
    int input;
    do {
        in >> input;
    } while (input < 1 && input > 6);

    switch (input) {
        // case 1:
        //     gameTime.setDate(1, 3, 1848);  // user option March
        //     break;
        case 2:
            gameTime.setDate(1, 4, 1848);  // user option April
            break;
        case 3:
            gameTime.setDate(1, 5, 1848);  // user option May
            break;
        case 4:
            gameTime.setDate(1, 6, 1848);;  // user option June
            break;
        case 5:
            gameTime.setDate(1, 7, 1848);;  // user option July
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


