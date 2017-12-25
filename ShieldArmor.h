//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_SHEILDARMOR_H
#define EX2_CPP_SEFI_SHEILDARMOR_H

#include <memory>

#include "Armor.h"
#include "Weapon.h"
#include "Soldier.h"

class ShieldArmor: public Armor {


public:
    ShieldArmor(const Point& position, double defensePower);
    ~ShieldArmor();
    double defend(Weapon* weapon);
    void useObject(Soldier* soldier);
    void drop(Soldier* soldier);

    double defend(std::shared_ptr<Weapon> weapon);
};


#endif //EX2_CPP_SEFI_SHEILDARMOR_H
