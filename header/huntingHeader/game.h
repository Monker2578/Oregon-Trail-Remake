#ifndef GAME_H
#define GAME_H

#include "header/huntingHeader/player.h"
#include "header/huntingHeader/animals/animal.h"
#include "header/wagon.h"

class Game {
    private:
        Player player;
        Animal* currentAnimal;
        bool alive;
        int turns;
        int totalFood;
        int bearTurnsOnScreen = 0;

        // Reference to the wagon inventory
        Wagon& w;

        // Game Display System
        void displayGame() const;

        // Animal Position System
        void printAnimalPosition() const;
        
        // Text Centering Helper
        std::string stringCentering(const std::string& text) const;

        // Player Position System
        void printPlayerPosition() const;

        // Game Reset System
        void gameReset();
        
    public:
        // Constructor
        Game(Wagon& w);

        // Destructor
        ~Game();

        // Hunting Game System
        void runHunt();

        // Animal Spawning System
        void spawnAnimal();

        // Animal Movement System (package)
        void animalMovement();

        // Bear Checking System
        void bearCheck();
        
        // Player Shooting System
        void shoot(int section);

        // Hunt Completion System
        void endHunt();


        // ===== Getters Mainly for Testing :) =====

        // Checks Player Status
        bool isAlive() const { return alive; }

        // Return Current Turn Count
        int getTurns() const { return turns; }

        // Return Current Total Food Gained During Hunting
        int getTotalFood() const { return totalFood; }

        // Returns Current Bear's Turn On Screen
        int getBearTurnsOnScreen() const { return bearTurnsOnScreen; }

        // Checks if Animal Spawned
        bool animalRemained() const { return currentAnimal != nullptr; }

        // Spawns a Set Animal
        void placeAnimal(Animal* selected) {
            delete currentAnimal;
            currentAnimal = selected;
        }
};

#endif