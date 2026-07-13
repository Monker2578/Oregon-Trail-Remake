#ifndef RIVER_H
#define RIVER_H

#include <iostream>
#include "locations.h"

class River : public Locations {
    private:
        LocationType type = LocationType::river;
        int width;
        double depth;
    public:
        // Constructor
        River(std::string name, bool isDetour, Locations* next, int distance);

        // Getters
        const std::string& getName() const override;
        int getDistance() const override;
        bool getIsDetour() const override;
        LocationType getType() const override;
};

#endif