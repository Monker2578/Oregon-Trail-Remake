#ifndef RABBIT_H
#define RABBIT_H

#include "header/huntingHeader/animals/animal.h"

class Rabbit : public Animal {
    public:
        Rabbit(int section);
        std::string getName() const override;
        bool canHarmPlayer() const override;
};

#endif