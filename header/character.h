#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>

enum class Condition {excellent, good, fair, poor, critical, dead};

class Character {
    private:
        std::string name;
        int health;
        bool isAlive;
        std::string profession;
    public:
        // Constructor
        Character(const std::string& name);

        // Character Name System
        std::string getName() const;
        void setName(const std::string& name);

        // Character Health System
        int getHealth() const;
        bool checkAlive() const;
        Condition getCondition() const;

        // Character Damage & Healing System
        void takeDamage(int damageAmt);
        void heal(int healAmt);
};


#endif
