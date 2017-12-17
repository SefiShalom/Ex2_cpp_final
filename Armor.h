//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_ARMOR_H
#define EX2_CPP_SEFI_ARMOR_H

#include "CollectableObject.h"
#include "Weapon.h"

class Armor: public CollectableObject{
    double _defensePower;

public:
    Armor(Point* position, double defensePower);
    virtual ~Armor()=0;
    virtual double defend(Weapon* weapon)=0;
    double getDefensePower();
};

#endif //EX2_CPP_SEFI_ARMOR_H
