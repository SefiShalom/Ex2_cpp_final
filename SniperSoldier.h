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
    static std::string identifier;

    SniperSoldier(const Point &location, short army);

    double calculateHitChance(Soldier &enemy) const;

    virtual double calculateHitChance(std::shared_ptr<Soldier> enemy);

    void walk();

    virtual int getType();
};


#endif //EX2_CPP_SEFI_SNIPERSOLDIER_H
