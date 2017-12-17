//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_SHEILDARMOR_H
#define EX2_CPP_SEFI_SHEILDARMOR_H

#include "Armor.h"
#include "Weapon.h"


class SheildArmor: public Armor {

    SheildArmor(Point* position, double defensePower);
    ~SheildArmor();
    double defend(Weapon* weapon);
};


#endif //EX2_CPP_SEFI_SHEILDARMOR_H
