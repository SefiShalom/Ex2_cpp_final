//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_BODYARMOR_H
#define EX2_CPP_SEFI_BODYARMOR_H



#include "Armor.h"

class BodyArmor: public Armor {

    BodyArmor(Point* position, double defensePower);
    ~BodyArmor();
    double defend(Weapon* weapon);
};


#endif //EX2_CPP_SEFI_BODYARMOR_H
