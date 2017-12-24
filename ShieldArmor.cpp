//
// Created by Sefi on 16/12/2017.
//

#include "ShieldArmor.h"

ShieldArmor::ShieldArmor(Point* position, double defensePower)
        : Armor(position,defensePower){}

ShieldArmor::~ShieldArmor() {std::cout << "ShielArmor dtor" << std::endl;}

double ShieldArmor::defend(Weapon *weapon) {
    return weapon->attackArmor(this);
}

void ShieldArmor::useObject(Soldier *soldier) {
    soldier->pickObject(this);
}

void ShieldArmor::drop(Soldier *soldier) {
    setCurrentPosition(soldier->getPosition());
    soldier->set_shield(nullptr);
}

