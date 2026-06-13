#include <cstdlib>
#include <iostream>
#include <limits>
#include "header/huntingHeader/game.h"
#include "header/huntingHeader/animals/bear.h"
#include "header/huntingHeader/animals/deer.h"
#include "header/huntingHeader/animals/rabbit.h"
#include "header/huntingHeader/animals/squirrel.h"

// Constructor
Game::Game(Wagon& w) : w(w) {
    currentAnimal = nullptr;
    alive = true;
    turns = 10; // 10 turns limit
    totalFood = 0;
}

// Destructor
Game::~Game() {
    delete currentAnimal;
    currentAnimal = nullptr;
}

// Runs the hunting minigame
void Game::runHunt() {
    // Reset the game before proceeding
    gameReset();

    // Checks if turns did not ran out, ammunition did not ran out, and the player is still alive
    while (turns > 0 && w.getItem(itemType::ammunition) > 0 && alive) {
        // Spanws animal if it does not exist yet
        if (currentAnimal == nullptr) { spawnAnimal(); }

        // Display the game on terminal
        displayGame();

        char input;

        // Different options
        if (!(std::cin >> input)) { // Checks if the input is a char
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please input a valid option!" << "\n" << "\n";
            continue; // Continues until a valid input
        } else if (input == 'a' || input == 'A') { // Left movement for player
            player.turnLeft();
            std::cout << "\n" << "\n";
        } else if (input == 'd' || input == 'D') { // Right movement for player
            player.turnRight();
            std::cout << "\n" << "\n";
        } else if (input == 's' || input == 'S') { // Shooting for player
            shoot(player.getSection());
            std::cout << "\n" << "\n";
        } else { // If the input is not one of the 3 viable options
            std::cout << "Please input a valid option!" << "\n" << "\n";
            continue; // Continues until a valid input
        }

        // Moves the animal each turn
        animalMovement();

        // Check if a bear has gotten 3 turns
        bearCheck();

        // Reduces turn by one
        turns--;
    }

    // End hunt when one of the condition is not satisfied
    endHunt();
}

// Displays the hunting game terminal interface
void Game::displayGame() const {
    std::cout << "==================== Hunt Begin! ====================" << "\n";
    printAnimalPosition(); // Prints the animal position interface
    printPlayerPosition(); // Prints the player position interface
    std::cout << "=====================================================" << "\n";

    // Inventory and hunt session information
    std::cout << "Current Ammunition: " << w.getItem(itemType::ammunition) << "\n";
    std::cout << "Current Food Gained: " << totalFood << "\n";
    std::cout << "Turns left: " << turns << "\n" << "\n";

    // Game control information
    std::cout << "Movement: ('a' to move left), ('d' to move right), (s to shoot)" << "\n";
    std::cout << "Choose your option: ";
}

// Prints the animal position 
void Game::printAnimalPosition() const {
    // Three default strings for the 3 sections and are empty on default
    std::string p1 = "                 ";
    std::string p2 = "                 ";
    std::string p3 = "                 ";

    if (currentAnimal != nullptr) { // Checks if the current animal exists
        // String to store the name of the animal
        std::string animalPosition = stringCentering(currentAnimal -> getName());

        // Replaces the default string with the name string based on current animal's section
        if (currentAnimal -> getSection() == 0) { // If the current animal is in the leftmost section
            p1 = animalPosition;
        } else if (currentAnimal -> getSection() == 1) { // If the current animal is in the middle section
            p2 = animalPosition;
        } else if (currentAnimal -> getSection() == 2) { // If the current animal is in the rightmost section
            p3 = animalPosition;
        }
    }

    // Prints the final result
    std::cout << p1 << "|" << p2 << "|" << p3 << "\n";
}

// Centers the text in the middle of a string of length 17
std::string Game::stringCentering(const std::string& text) const {
    // Calculates the padding for the text
    int estimateSpace = (17 - text.length()) / 2;

    return std::string(estimateSpace, ' ') + text + std::string(17 - estimateSpace - text.length(), ' ');
}

// Prints the player position
void Game::printPlayerPosition() const {
    // Three default strings for the 3 sections and are empty on default
    std::string p1 = "                 ";
    std::string p2 = "                 ";
    std::string p3 = "                 ";

    // Hardcoded player string because am lazy
    std::string playerPosition = "     PLAYER      ";
    
    // Replaces the default string with the name string based on current player's section
    if (player.getSection() == 0) { // If the player is in the leftmost section
        p1 = playerPosition;
    } else if (player.getSection() == 1) { // If the player is in the middle section
        p2 = playerPosition;
    } else if (player.getSection() == 2) { // If the player is in the rightmost section
        p3 = playerPosition;
    }

    // Prints the final result
    std::cout << p1 << "|" << p2 << "|" << p3 << "\n";
}

// Spawns animal
void Game::spawnAnimal() {
    // Randomizer
    int chooseAnimal = std::rand() % 100;
    int chooseSection = (std::rand() % 2) * 2; // The animal can only spawn on the edge of the screen

    // Different animal spawn based on their spawnrate
    if (chooseAnimal < 50) {
        currentAnimal = new Squirrel(chooseSection);
    } else if (chooseAnimal < 85) {
        currentAnimal = new Rabbit(chooseSection);
    } else if (chooseAnimal < 95) {
        currentAnimal = new Deer(chooseSection);
    } else {
        currentAnimal = new Bear(chooseSection);
    }
}

// Moves animal
void Game::animalMovement() {
    if (currentAnimal != nullptr) { // Checks if the animal actually exists
        currentAnimal -> moveSection(); // Animal moves

        // Animals can go offscreen
        if (currentAnimal -> getSection() < 0 || currentAnimal -> getSection() > 2) {
            // If the animal was a bear, the bear counter resets
            if (currentAnimal -> getName() == "Bear") {
                bearTurnsOnScreen = 0;
            }

            // Deallocation
            delete currentAnimal;
            currentAnimal = nullptr;
        }
    }
}

// Checks for the bear counter
void Game::bearCheck() {
    // Checks if animal actually exists and if it is a bear
    if (currentAnimal != nullptr && currentAnimal -> getName() == "Bear") {
        // Increase counter by one
        bearTurnsOnScreen++;

        if (bearTurnsOnScreen >= 3) {
            alive = false; // Player is injured if counter goes reaches 3
            bearTurnsOnScreen = 0; // Counter resets so it does not affect the next hunt session
        }
    } else { // Resets counter if the bear disappeared offscreen before the counter reached three
        bearTurnsOnScreen = 0;
    }
}

// Handles shooting mechanics
void Game::shoot(int section) {
    // Uses one bullet
    w.useItem(itemType::ammunition, 1);

    // Checks if the animal exists and if the animal is in the same section as the player when the player shoots
    if (currentAnimal != nullptr && section == currentAnimal -> getSection()) {
        // Adds the animal's food gain towards the total food earned in session
        totalFood += currentAnimal -> getFoodGain();

        // Hit success message
        std::cout << "You hit a " << currentAnimal -> getName() << " and gained " << currentAnimal -> getFoodGain() << " food!" << "\n" << "\n";

        // Deallocation
        delete currentAnimal;
        currentAnimal = nullptr;
    } else {
        // Hit failure message
        std::cout << "You missed!" << "\n" << "\n";
    }
}

// Ends the hunt with all the ending processes
void Game::endHunt() {
    std::cout << "================= Hunt Over =================" << "\n";

    // Different situations trigger different display messages
    if (!alive) { // If player is injured
        std::cout << "You have been injured by a bear!" << "\n";
    } else if (w.getItem(itemType::ammunition) == 0) { // If ammo runs out
        std::cout << "You ran out of bullets!" << "\n";
    } else { // If turns ran out
        std::cout << "Times out!" << "\n";
    }

    // Adds the total food gained during the hunt session to the inventory
    w.gainItem(itemType::food, totalFood);
    std::cout << "Total food gained during hunt session: " << totalFood << "\n";

    std::cout << "=============================================" << "\n" << "\n";
}

// Resets the game if the game object is reused
void Game::gameReset() {
    turns = 10;
    alive = true;
    bearTurnsOnScreen = 0;
    totalFood = 0;
    delete currentAnimal;
    currentAnimal = nullptr;
}