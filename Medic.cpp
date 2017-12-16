//
// Created by damir on 16-Dec-17.
//

#include "Medic.h"

Medic::Medic(const Point &currPosition, size_t hp, double speed, const int army)
        : Soldier(currPosition, hp, speed, army) {}

void Medic::heal(Soldier &injured) {
    if (injured.getArmy() == _army)
        injured.healMe();
}


void Medic::attack(Soldier *target) {
    target->defend(10);
}

void Medic::pickObject(CollectableObject *object) {
    // TODO
}

void Medic::dropObject(Point position) {
    // TODO
}

void Medic::defend(double attack) {

}

const Point Medic::getCurrentPosition() {
    return Point(*_currPosition);
}

void Medic::whoAreYou() {
    std::cout << "I am a medic." << std::endl;
}

