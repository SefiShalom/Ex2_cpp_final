//
// Created by damir on 16-Dec-17.
//

#include "Medic.h"

Medic::Medic(const Point &currPosition, size_t hp, double speed, const int army)
        : Soldier(currPosition, hp, speed, army) {

}

void Medic::heal(Soldier* injured) {
    if (injured->getArmy() == _army)
        injured->healMe();
}


void Medic::attack(Soldier *target) {

}

void Medic::pickObject(CollectableObject *object) {
    // TODO
}

void Medic::dropObject(Point position) {
    // TODO
}

void Medic::defend(Weapon* weapon) {
    double reduce = _shield->defend(weapon);
    std::cout << "Medic had HP: " << _hp << ", but he was attacked so now he has HP: " << _hp-reduce << std::endl;
    _hp -= reduce;
//    double reducer = 0;
//    if (_bodyarmor != nullptr)
//        reducer += weapon->attackArmor(_bodyarmor);
//    if (_shield != nullptr)
//        reducer += weapon->attackArmor(_shield);
}

const Point Medic::getCurrentPosition() {
    return Point(*_currPosition);
}

void Medic::whoAreYou() {
    std::cout << "I am a medic." << std::endl;
}

