#include "locations.h"

const std::string& Locations::getName() const {
    return data.name;
}

int Locations::getDistance() const {
    return data.distanceToNextLocation;
}

bool Locations::getIsDetour() const {
    return data.isDetour;
}

void Locations::setNextLocation(Locations* newLocation) {
    nextLocation = newLocation;
}

Locations* Locations::getNextLocation() const {
    return nextLocation;
}