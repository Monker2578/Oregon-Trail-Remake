#ifndef MAP_H
#define MAP_h

#include "Locations/locations.h"

class Map {
    private:
        Locations* head;
        int totalDistanceTraveled;
        Locations* curr = nullptr;
    public:
        Map();
        ~Map();

        int initilizeLocation();

        int getTotalDistanceTraveled() const;
        void incrementTotalDistance(int distance);

        void displayMap() const;

        Locations* getCurrLocation() const;
        Locations* getNextLocation() const;
        void updateCurrLocation(int distance);
};

#endif