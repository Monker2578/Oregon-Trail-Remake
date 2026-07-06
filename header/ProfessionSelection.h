#ifndef PROFESSION_SELECTION_H
#define PROFESSION_SELECTION_H

#include "header/wagon.h"

class ProfessionSelection {
    public:
        Wagon& w; // Reference to the Wagon object to apply profession buffs

        // Constructor to initialize the ProfessionSelection with a reference to a Wagon object
        ProfessionSelection(Wagon& w) : w(w) {}

        // Display the profession selection menu
        void selectProfession();

        // Handle the logic for the selected profession
        void selectProfessionLogic(int choice);

        // Display the differences between professions
        void professionDifference() const;
};

#endif