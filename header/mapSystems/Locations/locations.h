#ifndef LOCATIONS_H
#define LOCTIONS_H

#include <iostream>

enum class LocationType {landmark, fort, river};

struct CommonAttributes {
    std::string name;
    bool isDetour;
    int distanceToNextLocation;
};

class Locations {
    protected:
        CommonAttributes data;
        Locations* nextLocation = nullptr;
    public:
        // Constructor
        Locations(CommonAttributes& c) : data(c) {}

        // Getters
        const std::string& getName() const;
        int getDistance() const;
        bool getIsDetour() const;
        Locations* getNextLocation() const;
        virtual LocationType getType() const = 0;

        // Setters
        void setNextLocation(Locations*);
};

#endif