//
// Created by damir on 19-Dec-17.
//

#include "Fighter.h"

Fighter::Fighter(const Point &position, size_t hp, double speed, const int army)
        : Soldier(position, hp, speed, army), _weapon(new Fists) {}

void Fighter::attack(Soldier* target) {
    if(getRandom() <= calculateHitChance(target))
        target->defend(_weapon);
    else std::cout << "Missed" << std::endl;
}

float Fighter::getRandom(){
    float r = ((double) rand() / (RAND_MAX));
    std::cout << "RANDON EQUALS " << r << std::endl;
    return r;
}


void Fighter::pickObject(Weapon *weapon) {
    if (weapon->isCarried()) return;
    if (_weapon != nullptr){
        _weapon->drop(this);
        set_weapon(nullptr);
    }
    _weapon = weapon;
    weapon->setCarried(true);
    weapon->setLocation(UNREACHABLE_POINT);
}

Fighter::~Fighter() {

}

void Fighter::set_weapon(Weapon *weapon) {
    _weapon = weapon;
}

void Fighter::performAction(Soldier *soldier) {
    if(getArmy() != soldier->getArmy()) attack(soldier);
    else std::cout << "We are brothers in arms!" << std::endl;
}

void Fighter::performAction(Weapon *weapon) {
    pickObject(weapon);
}


