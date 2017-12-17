//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_SHEILDARMOR_H
#define EX2_CPP_SEFI_SHEILDARMOR_H

#include "Armor.h"
#include "Weapon.h"


class ShieldArmor: public Armor {


    public:
        ShieldArmor(Point* position, double defensePower);
        ~ShieldArmor();
        double defend(Weapon* weapon);
};


#endif //EX2_CPP_SEFI_SHEILDARMOR_H