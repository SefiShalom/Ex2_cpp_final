//
// Created by Sefi on 08/12/2017.
//
#include "Weapon.h"
#include "Fighter.h"

Weapon::Weapon(const Point& position, const double power, size_t bulletsPerShot):
        CollectableObject(position),_power(power),_bulletsPerShot(bulletsPerShot){}

Weapon::~Weapon() {}

double Weapon::shoot(){
    return _power*_bulletsPerShot;
}

const double Weapon::getPower() const {
    return _power;
}

void Weapon::acceptAction(Soldier* soldier) {
    soldier->performAction(this);
}

void Weapon::useObject(Fighter *fighter) {
    fighter->pickObject(this);
}


