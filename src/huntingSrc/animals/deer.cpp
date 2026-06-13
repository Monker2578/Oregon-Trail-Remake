#include "header/huntingHeader/animals/deer.h"

Deer::Deer(int section) : Animal(section, 150) {}

std::string Deer::getName() const {
    return "Deer";
}