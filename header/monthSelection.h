#ifndef MONTHSELECTION_H
#define MONTHSELECTION_H

#include "monthSelectionDisplay.h"
#include <iostream>

struct Date {
    int month;
    int day;
    int year;
};

class MonthSelection {
    public:
        MonthSelection(std::ostream& , std::istream& );
        Date getStartDate() const;
        
    private:
        void inputSelection (MonthSelectionDisplay& , std::istream& , std::ostream& );
        void adviceSelection(std::ostream& ,std::istream& ,MonthSelectionDisplay& );
        Date gameTime;

};
#endif