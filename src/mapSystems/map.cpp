#include "map.h"
#include "Locations/fort.h"
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
    CommonAttributes Independence {"Independence", false, 102};
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

        // Create the appropriate location object based on the option
        if (option == 0) { // Landmark

            // Create a new Landmark object with the read attributes
            CommonAttributes landmark_temp {name, isdetour, distance};
            Landmark* newLandmark = new Landmark(landmark_temp);
                
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
            CommonAttributes river_temp {name, isdetour, distance};
            River* newRiver = new River(river_temp, width, depth);

            curr -> setNextLocation(newRiver); // Set the next location of the current location to the new river
            curr = newRiver; // Move the current pointer to the new river

        } else if (option == 2) { // Fort

            // Create a new Fort object with the read attributes
            CommonAttributes fort_temp {name, isdetour, distance};
            Fort* newFort = new Fort(fort_temp);
            
            curr -> setNextLocation(newFort); // Set the next location of the current location to the new fort
            curr = newFort; // Move the current pointer to the new fort

        } else {
            std::cerr << "Invalid option in CSV file: " << option << std::endl; // Handle invalid option
        }
    }

    inFS.close(); // Close the input file stream
    return 0; // Return success code
}

//
int Map::getTotalDistanceTraveled() const {
    return totalDistanceTraveled;
}

void Map::incrementTotalDistance(int distance) {
    totalDistanceTraveled += distance;
}