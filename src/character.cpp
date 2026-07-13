#include "header/character.h"


// Constructor
Character::Character(const std::string& name) {
   this -> name = name;
   health = 100;
   isAlive = true;
}

// Getters
std::string Character::getName() const {
   return name;
}

int Character::getHealth() const {
   return health;
}

bool Character::checkAlive() const {
   return isAlive;
}

Condition Character::getCondition() const {
   if (health >= 80) { return Condition::excellent;
   } else if (health >= 60) { return Condition::good;
   } else if (health >= 40) { return Condition::fair;
   } else if (health >= 20) { return Condition::poor;
   } else { return Condition::critical; }
}

// Setters
void Character::setName(const std::string& name) {
   this -> name = name;
}

void Character::takeDamage(int damageAmt) {
   if (!isAlive) { return; } // Stop if the character is already dead


   health -= damageAmt; // Take Damage & update character health
   if (health <= 0) { // Character dies if heal depletes below 0
       health = 0;
       isAlive = false;
   }
}

void Character::heal(int healAmt) {
   if (!isAlive || health == 100) { return; } // Stop if the character is already dead or the health is at max


   health += healAmt; // Heal
   if (health > 100) { // Caps max health to 100
       health = 100;
   }
}