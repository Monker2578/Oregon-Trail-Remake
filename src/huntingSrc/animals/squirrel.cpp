#include "header/huntingHeader/animals/squirrel.h"

Squirrel::Squirrel(int section) : Animal(section, 15) {}

bool Squirrel::canHarmPlayer() const {
    return false; // Squirrels cannot harm the player
}

std::string Squirrel::getName() const {
    return "Squirrel";
}