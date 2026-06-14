#include "header/huntingHeader/animals/animal.h"

// Constructor
Animal::Animal(int section, int foodGain) {
    this -> section = section;
    this -> foodGain = foodGain;
}

// Returns Animal Section
int Animal::getSection() const {
    return section;
}

// Returns Animal Food Gain
int Animal::getFoodGain() const {
    return foodGain;
}

// Animal Random Movement System
void Animal::moveSection() {
    int move = std::rand() % 3;
    switch (move) {
        case 0: // Animal doesn't move
            break;
        case 1:
            section++; // Animal moves right
            break;
        case 2:
            section--; // Animal moves left
            break;
    }
}