#ifndef FORT_H
#define FORT_H

#include <iostream>
#include "locations.h"

class Fort : public Locations {
    private:
        LocationType type = LocationType::fort;
    public:
        // Constructor
        Fort(CommonAttributes& c) : Locations(c) {}

        // Getters
        LocationType getType() const override;

        // Display Location Screen
        void display() const override;
};

#endif