//
// Created by damir on 19-Dec-17.
//

#include "Fighter.h"
#include "Missile.h"

Fighter::Fighter(const Point &position, size_t hp, double speed, const int army)
        : Soldier(position, hp, speed, army), _weapon(nullptr) {}

void Fighter::attack(Soldier* target) {
    if(getRandom() <= calculateHitChance(target))
        target->defend(_weapon);
    else std::cout << "Missed" << std::endl;
}

float Fighter::getRandom(){
    float r = ((double) rand() / (RAND_MAX));
    std::cout << "RANDON EQVALS " << r << std::endl;
    return r;
}

void Fighter::pickObject(BodyArmor *ba) {
    if (ba->isCarried()) return;
    if (_bodyarmor != nullptr) {
        _bodyarmor->drop(this);
        set_bodyarmor(nullptr);
    }
    _bodyarmor = ba;
    ba->setCarried(true);
    ba->setLocation(UNREACHABLE_POINT);
}

void Fighter::pickObject(ShieldArmor *sa) {
    if (sa->isCarried()) return;
    if (_shield != nullptr){
        _shield->drop(this);
        set_shield(nullptr);
    }
    _shield = sa;
    sa->setCarried(true);
    sa->setLocation(UNREACHABLE_POINT);
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
//    std::cout << "Fighter dtor" << std::endl;
}

void Fighter::set_weapon(Weapon *weapon) {
    _weapon = weapon;
}

void Fighter::performAction(Soldier *soldier) {
    attack(soldier);
}


