#ifndef LOCATIONS_H
#define LOCTIONS_H

#include <iostream>

enum class LocationType {landmark, fort, river};
enum class TerrainType {grassland = 0, mountainous = 1};

struct CommonAttributes {
    std::string name;
    bool isDetour;
    int distanceFromOrigin;
    TerrainType terrain;
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

        // Display Location Function
        virtual void display() const = 0;
};

#endif