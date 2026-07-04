#include "header/rations.h"

// Constructor
Rations::Rations() {
    level = RationLevel::filling; // Default to filling rations
}

// Get the current ration level
RationLevel Rations::getRationLevel() const {
    return level;
}

// Set the ration level
void Rations::setRationLevel(RationLevel l) {
    level = l;
}

// Calculate food consumed based on ration level
int Rations::foodConsumptionRate(RationLevel l) const {
    if (l == RationLevel::filling) {
        return 30; // Consumes 30 units of food per day
    } else if (l == RationLevel::meager) {
        return 20; // Consumes 20 units of food per day
    } else if (l == RationLevel::barebones) {
        return 10; // Consumes 10 units of food per day
    }

    return 0; // Error Handling: return 0 if no food consumption occurs
}

// Health drain based on ration level
int Rations::healthDrained() const {
    if (level == RationLevel::filling) {
        return 0; // No health drain
    } else if (level == RationLevel::meager) {
        return 1; // Minor health drain
    } else if (level == RationLevel::barebones) {
        return 2; // Significant health drain
    }

    return 0; // Error Handling: return 0 if no health drain occurs
}