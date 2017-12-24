//
// Created by damir on 19-Dec-17.
//

#include "Fists.h"

Fists::Fists()
        : Weapon(nullptr, FISTS_POWER, BULLETS_PER_SHOT) {}

Fists::~Fists() {std::cout << "Fists dtor" << std::endl;}

double Fists::attackArmor(BodyArmor *armor) {
    return 10;
}

double Fists::attackArmor(ShieldArmor *sheild) {
    return 10;
}

void Fists::useObject(Soldier* soldier){}
