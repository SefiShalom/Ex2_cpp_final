//
// Created by damir on 19-Dec-17.
//

#include "Fighter.h"

Fighter::Fighter(const Point &position, size_t hp, double speed, const int army)
        : Soldier(position, hp, speed, army){}

bool Fighter::attack(Soldier* target) {
    if(getRandom() <= calculateHitChance(target))
        return target->defend(_weapon);

        std::cout << "Missed" << std::endl;

        return false;
}

float Fighter::getRandom(){
    float r = ((double) rand() / (RAND_MAX));
    std::cout << "RANDOM EQUALS " << r << std::endl;
    return r;
}


void Fighter::pickObject(Weapon *weapon) {
    if (weapon->isCarried()) return;
    if (_weapon != nullptr){
        _weapon->drop(this);
//        set_weapon(nullptr);
    }
    _weapon = weapon;
    weapon->setCarried(true);
    weapon->setLocation(UNREACHABLE_POINT);
}

Fighter::~Fighter() {
    if (_weapon !=nullptr) {
//        delete _weapon;
    }
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


std::vector<MapObject*> Fighter::kill(){
    std::vector<MapObject*> objects;
    if(_weapon != nullptr) objects.emplace_back(_weapon);
    if(_shield != nullptr) objects.emplace_back(_shield);
    if(_weapon != nullptr) objects.emplace_back(_bodyarmor);

    objects.emplace_back(this);

    _isAlive = false;

    return objects;
}

