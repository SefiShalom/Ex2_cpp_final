//
// Created by Sefi on 08/12/2017.
//
#include "Weapon.h"

Weapon::Weapon(Point* position, size_t power, size_t bulletsPerShot):
        CollectableObject(position),_power(power),_bulletsPerShot(bulletsPerShot){}

Weapon::~Weapon() {}

size_t Weapon::shoot(){
    return _power*_bulletsPerShot;
}
