//
// Created by Sefi on 08/12/2017.
//


#ifndef EX2_CPP_WEAPON_H
#define EX2_CPP_WEAPON_H

#include <iostream>
#include "CollectableObject.h"

class ShieldArmor;
class BodyArmor;


class Weapon: public CollectableObject{

    size_t _power;
    size_t _bulletsPerShot;

public:
    Weapon(Point *position, size_t power, size_t bulletsPerShot);
    virtual ~Weapon() = 0;
    double shoot();
    virtual double attackArmor(ShieldArmor* sheild) = 0;
    virtual double attackArmor(BodyArmor* armor) = 0;
};


#endif //EX2_CPP_WEAPON_H
