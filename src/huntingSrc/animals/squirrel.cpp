#include "header/huntingHeader/animals/squirrel.h"

Squirrel::Squirrel(int section) : Animal(section, 15) {}

std::string Squirrel::getName() const {
    return "Squirrel";
}