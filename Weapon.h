//
// Created by Sefi on 08/12/2017.
//


#ifndef EX2_CPP_WEAPON_H
#define EX2_CPP_WEAPON_H

#include <memory>
#include <iostream>
#include "CollectableObject.h"

class ShieldArmor;
class BodyArmor;
class Fighter;

class Weapon: public CollectableObject, public std::enable_shared_from_this<Weapon> {

    const double _power;
    size_t _bulletsPerShot;

public:
    Weapon(const Point& position, const double power, size_t bulletsPerShot);
    virtual ~Weapon() = 0;
    double shoot();
    virtual double attackArmor(ShieldArmor* sheild) = 0;
    virtual double attackArmor(BodyArmor* armor) = 0;
    const double getPower() const;
    void acceptAction(Soldier* soldier);

    virtual void useObject(Fighter* fighter);

    virtual bool isFireArm() = 0;
};


#endif //EX2_CPP_WEAPON_H
