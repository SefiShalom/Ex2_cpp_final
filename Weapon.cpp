//
// Created by Sefi on 08/12/2017.
//
#include "Weapon.h"
#include "Fighter.h"

Weapon::Weapon(const Point& position, const double power, size_t bulletsPerShot):
        CollectableObject(position),_power(power),_bulletsPerShot(bulletsPerShot){}

Weapon::~Weapon() {
//    std::cout << "Weapon dtor" << std::endl;
}

double Weapon::shoot(){
    return _power*_bulletsPerShot;
}

void Weapon::drop(Fighter* soldier) {
    setLocation(soldier->getLocation());
    soldier->set_weapon(nullptr);
}

const double Weapon::getPower() const {
    return _power;
}


