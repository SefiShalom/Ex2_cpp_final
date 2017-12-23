//
// Created by Sefi on 16/12/2017.
//

#include "ShieldArmor.h"

ShieldArmor::ShieldArmor(Point* position, double defensePower)
        : Armor(position,defensePower){
    std::cout << "created ShieldArmor at " << *getPosition() << std::endl;
}

ShieldArmor::~ShieldArmor() {}

double ShieldArmor::defend(Weapon *weapon) {
    return weapon->attackArmor(this);
}

void ShieldArmor::useObject(Soldier *soldier) {
    soldier->pickObject(this);
}

