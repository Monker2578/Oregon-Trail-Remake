#include "river.h"

LocationType River::getType() const {
    return LocationType::river;
}

bool River::calculateSurvival(int option) {
    switch (option) {
        case 1:
            if (depth >= 8.0) {
                
            } else {
                return false;
            }
            break;
        case 2:
            break;
        case 3:
            // Remember to implement the $5 fee logic
            return true;
            break;
        default:
            std::cerr << "Invalid parameter";
    }
}