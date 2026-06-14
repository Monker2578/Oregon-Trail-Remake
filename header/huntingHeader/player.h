#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int section;
    public:
        // Constructor
        Player();

        // Getters
        int getSection() const;

        // Player Movement System
        void turnLeft();
        void turnRight();
};

#endif