#ifndef MONTHSELECTION_H
#define MONTHSELECTION_H

#include "monthSelectionDisplay.h"
#include "date.h"
#include <iostream>

class MonthSelection {
    private:
        void inputSelection (MonthSelectionDisplay& , std::istream& , std::ostream& );
        void adviceSelection(std::ostream& ,std::istream& ,MonthSelectionDisplay& );
        Date gameTime;
    public:
        MonthSelection(std::ostream& , std::istream& );
        const Date& getStartDate() const;
};

#endif