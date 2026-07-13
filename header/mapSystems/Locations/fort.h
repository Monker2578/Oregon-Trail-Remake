#ifndef FORT_H
#define FORT_H

#include <iostream>
#include "locations.h"

class Fort : public Locations {
    private:
        LocationType type = LocationType::fort;
    public:
        // Constructor
        Fort(std::string name, bool isDetour, Locations* next, int distance);

        // Getters
        const std::string& getName() const override;
        int getDistance() const override;
        bool getIsDetour() const override;
        LocationType getType() const override;
};

#endif