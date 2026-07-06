#ifndef DATE_H
#define DATE_H

// enum class MonthLabel {Janurary, Feburary, March, April, May, June, July, August, September, October, November, December};

class Date {
    private:
        int day;
        int month;
        int year;
        
        void monthCheck();
        void yearCheck();
        bool moreDaysMonth() const;
    public:
        Date();
        void setDate(int, int, int);
        void increment();
};

#endif