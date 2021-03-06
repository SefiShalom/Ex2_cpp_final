//
// Created by damir on 24-Dec-17.
//

#ifndef EX2_CPP_SEFI_SNIPERSOLDIER_H
#define EX2_CPP_SEFI_SNIPERSOLDIER_H


#include "Fighter.h"

#define SNIPER_SOLDIER_IDENTIFIER 222
#define SNIPER_SOLDIER_HP 80
#define SNIPER_SOLDIER_SPEED 2

class SniperSoldier : public Fighter {

public:

    SniperSoldier(const Point &location, short army);

    void walk();

    void healMe();

    double calculateHitChance(Soldier *enemy) const;

    std::ostream& toString (std::ostream& out);

    SoldierStrategy* getStrategy();

    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_SNIPERSOLDIER_H
