#ifndef PACING_H
#define PACING_H

#include <iostream>
enum class Pace {
    grueling,
    steady,
    slow,

};

class Pacing{
    public:
        Pacing();
        void changeSpeed(int );
        int getSpeed() const;
        Pace getPace() const; 
        
    private:
        Pace wagon_speed;
};

#endif