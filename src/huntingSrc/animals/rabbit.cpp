#include "header/huntingHeader/animals/rabbit.h"

Rabbit::Rabbit(int section) : Animal(section, 30) {}

std::string Rabbit::getName() const {
    return "Rabbit";
}