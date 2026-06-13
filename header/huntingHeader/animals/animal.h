#ifndef HUNT_H
#define HUNT_H

#include <string>
#include <cstdlib>

class Animal {
    private:
        int section;
        int foodGain;
    public:
        // Constructor
        Animal(int section, int foodGain);

        // Destructor
        virtual ~Animal() = default;

        // Animal Differentiation Method
        virtual std::string getName() const = 0;

        // Getters
        int getSection() const;
        int getFoodGain() const;

        // Animal Section Movement
        void moveSection();
};

#endif