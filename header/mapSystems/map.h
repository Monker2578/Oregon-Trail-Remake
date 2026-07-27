#ifndef MAP_H
#define MAP_h

#include "Locations/locations.h"

class Map {
    private:
        Locations* head;
        int totalDistanceTraveled;
    public:
        Map();
        ~Map();

        int initilizeLocation();

        int getTotalDistanceTraveled() const;
        void incrementTotalDistance(int distance);

        void displayMap() const;

        void currentLocation() const;
        
};

#endif