#ifndef LANDMARK_H
#define LANDMARK_H

#include <iostream>
#include "locations.h"

class Landmark : public Locations {
    private:
        LocationType type = LocationType::landmark;
    public:
        // Constructor
        Landmark(std::string name, bool isDetour, Locations* next, int distance);

        // Getters
        const std::string& getName() const override;
        int getDistance() const override;
        bool getIsDetour() const override;
        LocationType getType() const override;
};

#endif