//
// Created by Sefi on 16/12/2017.
//

#include "ShieldArmor.h"

ShieldArmor::ShieldArmor(const Point &position, double defensePower)
        : Armor(position, defensePower) {}

ShieldArmor::~ShieldArmor() {
//    std::cout << "ShielArmor dtor" << std::endl;
}

double ShieldArmor::defend(Weapon *weapon) {
    return weapon->attackArmor(this);
}


void ShieldArmor::useObject(Soldier *soldier) {
    soldier->pickObject(this);
}

void ShieldArmor::drop(Soldier *soldier) {
    setLocation(soldier->getLocation());
}

void ShieldArmor::acceptAction(Soldier* soldier) {
    soldier->performAction(this);
}

