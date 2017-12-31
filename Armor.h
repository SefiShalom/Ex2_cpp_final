//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_ARMOR_H
#define EX2_CPP_SEFI_ARMOR_H

#include <memory>
#include "CollectableObject.h"

class Weapon;

class Armor: public CollectableObject{
    double _defensePower;

public:
    Armor(const Point& position, double defensePower);
    virtual ~Armor()=0;
    virtual double defend(Weapon* weapon)=0;
    virtual void drop(Soldier* soldier) = 0;
    double getDefensePower();
};

#endif //EX2_CPP_SEFI_ARMOR_H
