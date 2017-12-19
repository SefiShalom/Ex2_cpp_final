//
// Created by damir on 19-Dec-17.
//

#ifndef EX2_CPP_SEFI_FIGHTER_H
#define EX2_CPP_SEFI_FIGHTER_H


#include "Soldier.h"

class Fighter : public Soldier {

    Weapon* _weapon;


public:
    Fighter(const Point& currPosition, size_t hp, double speed, const int army);

    virtual void attack(Soldier *target);

};


#endif //EX2_CPP_SEFI_FIGHTER_H
