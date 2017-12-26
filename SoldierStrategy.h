//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_SOLDIERSTRATEGY_H
#define EX2_CPP_SEFI_SOLDIERSTRATEGY_H


#include "Soldier.h"

#define WEAPON_RET 1
#define ARMOR_RET 2
#define ENEMY_RET 3
#define FRIENDLY_RET 4

class SoldierStrategy {

public:

    virtual int applyStrategy(Soldier* soldier) = 0;

};


#endif //EX2_CPP_SEFI_SOLDIERSTRATEGY_H
