#ifndef BEAR_H
#define BEAR_H

#include "header/huntingHeader/animals/animal.h"

class Bear : public Animal {
    public:
        Bear(int section);
        std::string getName() const override;
};

#endif