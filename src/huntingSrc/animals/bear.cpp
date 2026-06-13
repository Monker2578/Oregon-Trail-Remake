#include "header/huntingHeader/animals/bear.h"

Bear::Bear(int section) : Animal(section, 300) {}

std::string Bear::getName() const {
    return "Bear";
}