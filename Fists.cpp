//
// Created by damir on 19-Dec-17.
//

#include "Fists.h"

Fists::Fists()
        : Weapon(UNREACHABLE_POINT, FISTS_POWER, FISTS_BULLETS_PER_SHOT) {}

Fists::~Fists() {std::cout << "Fists dtor" << std::endl;}

double Fists::attackArmor(BodyArmor *armor) {
    return 10;
}

double Fists::attackArmor(ShieldArmor *sheild) {
    return 10;
}

void Fists::useObject(Soldier* soldier){

}

void Fists::drop(Fighter *figter) {
    delete this;
}

std::ostream &Fists::toString(std::ostream &out) {
    out << "Fists" << std::endl;
    return out;
}
