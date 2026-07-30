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
        River::River(CommonAttributes& c, int w, int d) : Locations(c), width(w), depth(d) {}

        // Getters
        LocationType getType() const override;

        // Display Location Screen
        void display() const override;

        // River Crossing Survival Calculation
        bool calculateSurvival(int option);
};

#endif