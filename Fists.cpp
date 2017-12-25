//
// Created by damir on 19-Dec-17.
//

#include "Fists.h"

Fists::Fists()
        : Weapon(UNREACHABLE_POINT, FISTS_POWER, BULLETS_PER_SHOT) {}

Fists::~Fists() {std::cout << "Fists dtor" << std::endl;}

double Fists::attackArmor(BodyArmor *armor) {
    return 10;
}

double Fists::attackArmor(ShieldArmor *sheild) {
    return 10;
}

void Fists::useObject(Soldier* soldier){}

void Fists::drop(Fighter *figter) {

}


double Fists::attackArmor(std::shared_ptr<ShieldArmor> shield) {
    return FISTS_POWER;
}

double Fists::attackArmor(std::shared_ptr<BodyArmor> bodyarmor) {
    return FISTS_POWER;
}

void Fists::useObject(std::shared_ptr<Soldier> soldier) {}

void Fists::drop(std::shared_ptr<Fighter> fighter) {

}
