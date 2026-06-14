#ifndef SQUIRREL_H
#define SQUIRREL_H

#include "header/huntingHeader/animals/animal.h"

class Squirrel : public Animal {
    public:
        Squirrel(int section);
        std::string getName() const override;
        bool canHarmPlayer() const override;
};

#endif