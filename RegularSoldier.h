//
// Created by Sefi on 24/12/2017.
//

#ifndef EX2_CPP_SEFI_REGULARSOLDIER_H
#define EX2_CPP_SEFI_REGULARSOLDIER_H


#include "Fighter.h"

#define REGULAR_SOLDIER_HP 100
#define REGULAR_SOLDIER_SPEED 2
#define REGULAR_SOLDIER_RUNNING_SPEED 4

class RegularSoldier: public Fighter {

public:
    RegularSoldier(const Point& position, const short army);
    virtual ~RegularSoldier();

    void healMe();

    double calculateHitChance(Soldier *enemy) const;

    virtual void walk();

    virtual void run();
};


#endif //EX2_CPP_SEFI_REGULARSOLDIER_H
