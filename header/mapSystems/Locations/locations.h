#ifndef LOCATIONS_H
#define LOCTIONS_H

#include <iostream>

enum class LocationType {landmark, fort, river};

class Locations {
    protected:
        std::string name;
        bool isDetour;
        Locations* nextLocation = nullptr;
        int distanceToNextLocation;
    public:
        // Constructor
        Locations(std::string name, bool isDetour, Locations* next, int distance);

        // Getters
        const virtual std::string& getName() const = 0;
        virtual int getDistance() const = 0;
        virtual bool getIsDetour() const = 0;
        virtual LocationType getType() const = 0;
};

#endif