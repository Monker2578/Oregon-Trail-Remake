#ifndef LOCATIONS_H
#define LOCTIONS_H

#include <iostream>

enum class LocationType {landmark, fort, river};

struct CommonAttributes {
    std::string name;
    bool isDetour;
    Locations* nextLocation = nullptr;
    int distanceToNextLocation;
};

class Locations {
    protected:
        CommonAttributes data;
    public:
        // Constructor
        Locations(CommonAttributes& c) : data(c) {}

        // Getters
        const std::string& getName() const;
        int getDistance() const;
        bool getIsDetour() const;
        virtual LocationType getType() const = 0;
};

#endif