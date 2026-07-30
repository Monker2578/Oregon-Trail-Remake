#include "map.h"
#include "header/mapSystems/Locations/fort.h"
#include "header/mapSystems/Locations/landmark.h"
#include "header/mapSystems/Locations/river.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor for the Map class
Map::Map() {
    int mapCreated = initilizeLocation();
    if (mapCreated == 1) {
        std::cerr << "Failed to initilize map" << std::endl;
        exit(EXIT_FAILURE);
    }
    curr = head -> getNextLocation();
    totalDistanceTraveled = 0;
}

// Destructor for the Map class
Map::~Map() {
    Locations* current = head;
    while (current != nullptr) {
        Locations* next = current -> getNextLocation();
        delete current;
        current = next;
    }
}

// NOTE: DETOUR IS PLANNED BUT IS GOING TO BE IMPLEMENT IN v2 DUE TO TIME CONSTRINTS
int Map::initilizeLocation() {
    CommonAttributes Independence {"Independence", false, 0};
    head = new Fort(Independence);

    std::ifstream inFS("src/mapSystems/locations.csv");

    if (!inFS.is_open()) {
        return 1; // Return an error code if the file cannot be opened
    }

    std::string line;
    int option;
    std::string name;
    bool isdetour;
    int distance;
    int terrain;
    Locations* curr = head;
    
    std::getline(inFS, line); // Skip the first line (header)

    while (std::getline(inFS, line)) { // Read each line from the CSV file
        std::stringstream ss(line); // Create a stringstream from the line
        
        ss >> option; // Reads type of location
        ss.ignore(); // Ignores commas

        std::getline(ss, name, ',');
        
        ss >> isdetour; // Reads the bool if its detour or not
        ss.ignore();
        
        ss >> distance; // Reads distance to next location
        ss.ignore();

        ss >> terrain; // Reads the terrain of the location
        ss.ignore();

        // Creates the common attributes of the location
        CommonAttributes temp {name, isdetour, distance, static_cast<TerrainType>(terrain)};

        // Create the appropriate location object based on the option
        if (option == 0) { // Landmark

            // Create a new Landmark object with the read attributes
            Landmark* newLandmark = new Landmark(temp);
                
            curr -> setNextLocation(newLandmark); // Set the next location of the current location to the new landmark
            curr = newLandmark; // Move the current pointer to the new landmark

        } else if (option == 1) { // River
            
            // reads the width and depth values
            int width;
            double depth;

            ss >> width;
            ss.ignore();
            ss >> depth;
            ss.ignore();
            
            // Create a new River object with the read attributes
            River* newRiver = new River(temp, width, depth);

            curr -> setNextLocation(newRiver); // Set the next location of the current location to the new river
            curr = newRiver; // Move the current pointer to the new river

        } else if (option == 2) { // Fort

            // Create a new Fort object with the read attributes
            Fort* newFort = new Fort(temp);
            
            curr -> setNextLocation(newFort); // Set the next location of the current location to the new fort
            curr = newFort; // Move the current pointer to the new fort

        } else {
            std::cerr << "Invalid option in CSV file: " << option << std::endl; // Handle invalid option
        }
    }

    inFS.close(); // Close the input file stream
    return 0; // Return success code
}

int Map::getTotalDistanceTraveled() const {
    return totalDistanceTraveled;
}

void Map::incrementTotalDistance(int distance) {
    totalDistanceTraveled += distance;
    updateCurrLocation(distance);
}

Locations* Map::getCurrLocation() const {
    return curr;
}

Locations* Map::getNextLocation() const {
    if (!curr -> getNextLocation()) {
       CommonAttributes endpoint_temp {"Willamette Valley", false, 1867};
       Landmark* endpoint = new Landmark(endpoint_temp);
       return endpoint;
    }
    
    return curr -> getNextLocation();
}

void Map::updateCurrLocation(int distance) {
    if (totalDistanceTraveled + distance >= curr -> getDistance()) {
        totalDistanceTraveled = curr -> getDistance();
        curr = curr -> getNextLocation();
    } else {
        totalDistanceTraveled += distance;
    }
} 

void Map::displayMap() const {
    std::cout;
    
}