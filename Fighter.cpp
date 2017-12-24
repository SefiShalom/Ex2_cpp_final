//
// Created by damir on 19-Dec-17.
//

#include "Fighter.h"

Fighter::Fighter( Point* currPosition, size_t hp, double speed, const int army)
        : Soldier(currPosition, hp, speed, army) {}

void Fighter::attack(Soldier *target) {
//    target->defend()
}

void Fighter::pickObject(BodyArmor *ba) {
    if(ba->isCarried()) return;
    if(_bodyarmor != nullptr) _bodyarmor->drop(this);
    _bodyarmor = ba;
    ba->setCarried(true);
    ba->setCurrentPosition(nullptr);
}

void Fighter::pickObject(ShieldArmor *sa) {
    if(sa->isCarried()) return;
    if(_shield != nullptr) _shield->drop(this);
    _shield = sa;
    sa->setCarried(true);
    sa->setCurrentPosition(nullptr);
}

void Fighter::pickObject(Weapon *weapon) {
    if(weapon->isCarried()) return;
    if(_weapon!= nullptr) _weapon->drop(this);
    _weapon = weapon;
    weapon->setCarried(true);
    weapon->setCurrentPosition(nullptr);
}

Fighter::~Fighter() {
    std::cout << "Fighter dtor" << std::endl;
}

void Fighter::set_weapon(Weapon* weapon) {
    _weapon = weapon;
}
