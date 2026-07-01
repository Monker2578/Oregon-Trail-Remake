#include "Pacing.h"


Pacing::Pacing(){

    wagon_speed = Pace::steady;
}

// class name: changeSpeed
// Sets wagon speed based on user option: input 1 = grueling; input 2 = steady; input 3 = slow
// return: none

void Pacing::changeSpeed(int option) {
    switch (option) {
        case 1 :
            wagon_speed = Pace::grueling;
            break;
        case 2:
            wagon_speed = Pace::steady;
            break;
        case 3:
            wagon_speed = Pace::slow;
            break;
        case 4:
            wagon_speed = Pace::rest;
            break;
    }
}

// class name: getSpeed
// returns the current speed of the wagon
// return: (int) -- current speed of the wagon
int Pacing::getSpeed() const{
    switch (wagon_speed) {
        case Pace::grueling :
            return 30;
        case Pace::steady :
            return 20;
        case Pace::slow :
            return 10;
        case Pace::rest :
            return 0;
    }
}

// class name: getPace
// returns the current pace of the wagon
// return: (enum) -- current space of the wagon
Pace Pacing::getPace() const {
    return wagon_speed;
}