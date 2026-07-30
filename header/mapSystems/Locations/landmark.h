#ifndef LANDMARK_H
#define LANDMARK_H

#include <iostream>
#include "locations.h"

class Landmark : public Locations {
    private:
        LocationType type = LocationType::landmark;
    public:
        // Constructor
        Landmark(CommonAttributes& c): Locations(c) {}

        // Getters
        LocationType getType() const override;

        // Display Location Screen
        void display() const override;
};

#endif