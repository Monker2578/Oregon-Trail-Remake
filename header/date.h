#ifndef DATE_H
#define DATE_H

#include <string>

// enum class MonthLabel {Janurary = 1, Feburary = 2, March = 3, April, May,
//                         June, July, August, September, October, November, December};

class Date {
    private:
        int day;
        int month;
        int year;
        
        void monthCheck();
        void yearCheck();
        bool moreDaysMonth() const;
        std::string_view numberToMonth(int month) const;
    public:
        Date();
        void setDate(int, int, int);
        void increment();
        int getMonth() const;
        std::string display() const;
};

#endif