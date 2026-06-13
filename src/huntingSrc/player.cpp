#include "header/huntingHeader/player.h"

// Constructor
Player::Player() {
    section = 1; // Player starts in the middle section
}

// Returns Current Player Section
int Player::getSection() const {
    return section;
}

// Player Turns Left
void Player::turnLeft() {
    if (section > 0) { section--; } // Player can not move left from section 0
}

// Player Turns Right
void Player::turnRight() {
    if (section < 2) { section++; } // Player can not move right from section 2
}