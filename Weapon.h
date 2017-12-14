//
// Created by Sefi on 08/12/2017.
//


#ifndef EX2_CPP_WEAPON_H
#define EX2_CPP_WEAPON_H

#include <iostream>
#include "CollectableObject.h"


class Weapon: public CollectableObject{

    size_t _power;
    size_t _bulletsPerShot;

public:
    Weapon(Point *position, size_t power, size_t bulletsPerShot);
    virtual ~Weapon() = 0;
    size_t shoot();
};


#endif //EX2_CPP_WEAPON_H
