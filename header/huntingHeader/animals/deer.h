#ifndef DEER_H
#define DEER_H

#include "header/huntingHeader/animals/animal.h"

class Deer : public Animal {
    public:
        Deer(int section);
        std::string getName() const override;
        bool canHarmPlayer() const override;
};

#endif