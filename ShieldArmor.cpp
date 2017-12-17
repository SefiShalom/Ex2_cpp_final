//
// Created by Sefi on 16/12/2017.
//

#include "ShieldArmor.h"

ShieldArmor::ShieldArmor(Point* position, double defensePower)
        : Armor(position,defensePower){}

ShieldArmor::~ShieldArmor() {}

double ShieldArmor::defend(Weapon *weapon) {
    return weapon->attackArmor(this);
}
