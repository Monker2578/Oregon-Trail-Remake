#include "date.h"

Date::Date() {
    day = 1;
    month = 3;
    year = 1848;
}

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::increment() {
    day++;
    monthCheck();
    yearCheck();
}

bool Date::moreDaysMonth() const {
    if ((month % 2 != 0 && month <= 7) || (month % 2 == 0 && month > 7)) {
        return true;
    }
    return false;
}

void Date::monthCheck() {
    // 1848 is a leap year, so Feb is counted as 30 days as journey would not take more than 4 years

    // Feb, Apr, June, September, November - 30 days
    // Jan, March, May, July, August, October, December - 31 days

    if (moreDaysMonth()) {
        if (day > 31) {
            month++;
            day = 1;
        }
    } else {
        if (day > 30) {
            month++;
            day = 1;
        }
    }
}

void Date::yearCheck() {
    if (month > 12) {
        year++;
        month = 1;
    }
}