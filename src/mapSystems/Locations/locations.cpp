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

