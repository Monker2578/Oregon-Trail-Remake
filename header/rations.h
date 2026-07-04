#ifndef RATIONS_H
#define RATIONS_H

enum class RationLevel { filling, meager, barebones };

class Rations {
    private:
        RationLevel level;
    public:
        Rations();

        RationLevel getRationLevel() const;

        void setRationLevel(RationLevel l);

        int foodConsumptionRate(RationLevel l) const;

        int healthDrained() const;
};

#endif