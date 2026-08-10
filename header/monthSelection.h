#ifndef MONTHSELECTION_H
#define MONTHSELECTION_H

#include "header/monthSelectionDisplay.h"
#include "header/date.h"
#include <iostream>

class MonthSelection {
    private:
        void inputSelection (MonthSelectionDisplay&, std::istream&, std::ostream&, Date& d);
        void adviceSelection(std::ostream&, std::istream&, MonthSelectionDisplay&, Date& d);
    public:
        MonthSelection(std::ostream&, std::istream&, Date& d);
};

#endif