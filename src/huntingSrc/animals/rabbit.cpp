#include "header/huntingHeader/animals/rabbit.h"

Rabbit::Rabbit(int section) : Animal(section, 30) {}

bool Rabbit::canHarmPlayer() const {
    return false; // Rabbits cannot harm the player
}

std::string Rabbit::getName() const {
    return "Rabbit";
}