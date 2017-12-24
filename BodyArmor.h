//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_BODYARMOR_H
#define EX2_CPP_SEFI_BODYARMOR_H


#include "Armor.h"
#include "Weapon.h"
#include "Soldier.h"

class BodyArmor : public Armor {

public:
    BodyArmor(const Point& position, double defensePower);

    ~BodyArmor();
    void drop(Soldier* soldier);
    double defend(Weapon *weapon);
    void useObject(Soldier* soldier);
};


#endif //EX2_CPP_SEFI_BODYARMOR_H
