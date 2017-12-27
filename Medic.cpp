//
// Created by damir on 16-Dec-17.
//

#include "Medic.h"

Medic::Medic(const Point& position, const short army)

        : Soldier(position, MEDIC_HP, MEDIC_SPEED, army), _fists(new Fists){}

void Medic::heal(Soldier* injured) {
    if (injured->getArmy() == _army)
        injured->healMe();
}

Medic::~Medic() {
    std::cout << "Medic dtor" << std::endl;
    delete _fists;
}

void Medic::attack(Soldier *target) {
    target->defend(_fists);
}

void Medic::whoAreYou() {
    std::cout << "I am a medic." << std::endl;
}


void Medic::healMe() {
//    setHP(MEDIC_HP);
}


void Medic::performAction(Soldier* soldier) {
    if(getArmy() == soldier->getArmy()) soldier->healMe();
    else attack(soldier);
}

void Medic::performAction(Weapon *weapon) {}

void Medic::walk() {
    Soldier::walk(MEDIC_SPEED);
}

std::ostream &Medic::toString(std::ostream &out) {
    out<< "Medic:" <<std::endl;
    out<< "Army: " << getArmy() <<std::endl;
    out<< "Location: " << getLocation() <<std::endl;
    out<< "HP: " << getHP() <<std::endl;
    return out;
}