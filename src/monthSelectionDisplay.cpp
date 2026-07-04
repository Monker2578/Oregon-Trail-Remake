#include "monthSelectionDisplay.h"

void MonthSelectionDisplay::adviceOption(std::ostream& out) {

    // display advice slide
    out << "You attend a public meeting held " << std::endl
        << "for 'folks with the California - " << std::endl
        << "Oregon fever.' You're told: " << std::endl
        << "If you leave too early, there" << std::endl
        << "won't be any grass for your " << std::endl
        << "oxen to eat. If you leave too" << std::endl
        << "late, you may not get to Oregon" << std::endl
        << "before winter comes. If you " << std::endl
        << "leave at just the right time," << std::endl
        << "there will be green grass and" << std::endl
        << "the weather will still be cool." << std::endl << std::endl
        << "Press SPACE BAR to continue" << std::endl
        << "---------------------------" << std::endl;
}

void MonthSelectionDisplay::monthSelectionPompt (std::ostream& out) {

    // displays prompt for month selection
    out << "It is 1848. You jumped off " << std::endl
        << "place for Oregon is Independence," << std::endl
        << "Missouri. You must decide which" << std::endl
        << "month to leave Independence." << std::endl << std::endl
        << "    1. March" << std::endl
        << "    2. April" << std::endl
        << "    3. May" << std::endl
        << "    4. June" << std::endl
        << "    5. July" << std::endl
        << "    6. Ask for advice" << std::endl << std::endl
        << "What is your choice? _" << std::endl;
}
