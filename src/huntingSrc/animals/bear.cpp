#include "header/huntingHeader/animals/bear.h"

Bear::Bear(int section) : Animal(section, 300) {}

bool Bear::canHarmPlayer() const {
    return true; // Bears can harm the player
}

std::string Bear::getName() const {
    return "Bear";
}