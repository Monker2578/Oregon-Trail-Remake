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

// Differentiates between months with 30 and 31 days
bool Date::moreDaysMonth() const {
    if ((month % 2 != 0 && month <= 7) || (month % 2 == 0 && month > 7)) {
        return true;
    }
    return false;
}

// Updates month
void Date::monthCheck() {
    // 1848 is a leap year, so Feb is counted as 30 days as journey would not take more than 4 years

    // Feb, Apr, June, September, November - 30 days
    // Jan, March, May, July, August, October, December - 31 days

    if (moreDaysMonth()) {
        if (day > 31) {
            // Increment month and reset day
            month++;
            day = 1;
        }
    } else {
        if (day > 30) {
            // Increment month and reset day
            month++;
            day = 1;
        }
    }
}

// Updates year
void Date::yearCheck() {
    if (month > 12) {
        // Increment year and reset month
        year++;
        month = 1;
    }
}

int Date::getMonth() const {
    return month;
}

std::string_view Date::numberToMonth(int m) const {
    switch (m) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Error";
    }
}

std::string Date::display() const {
    return std::string(numberToMonth(month)) + " " + std::to_string(day) + ", " + std::to_string(year);
}