#include "header/huntingHeader/animals/deer.h"

Deer::Deer(int section) : Animal(section, 150) {}

bool Deer::canHarmPlayer() const {
    return false; // Deer cannot harm the player
}

std::string Deer::getName() const {
    return "Deer";
}