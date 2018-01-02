//
// Created by Sefi on 08/12/2017.
//


#ifndef EX2_CPP_WEAPON_H
#define EX2_CPP_WEAPON_H

#include <iostream>
#include "CollectableObject.h"

class ShieldArmor;

class BodyArmor;

class Fighter;

class Weapon : public CollectableObject, public std::enable_shared_from_this<Weapon> {

    const double _power;
    size_t _bulletsPerShot;

public:


    //  Ctor which receives a point, shooting power and bullets per shot.
    Weapon(const Point &position, double power, size_t bulletsPerShot);

    //  Virtual dtor. Self explanatory.
    virtual ~Weapon() = 0;

    //  Returns the shooting power by multiplying it by bylletsPerShot
    double shoot();

    //  For Visitor purposes
    virtual double attackArmor(ShieldArmor *sheild) = 0;

    //  For Visitor purposes
    virtual double attackArmor(BodyArmor *armor) = 0;

    //  Simply returns the power of the weapon.
    const double getPower() const;
<<<<<<< HEAD
    void acceptAction(Soldier* soldier);
    virtual void useObject(Fighter* fighter);
=======

    //  For Visitor purposes.
    void acceptAction(Soldier *soldier);

    //  For Visitor purposes
    virtual void useObject(Fighter *fighter);

    //  Just for checking if it's Fists (or possibly a knife) or a fire arm.
>>>>>>> origin/damir-work
    virtual bool isFireArm() = 0;
};


#endif //EX2_CPP_WEAPON_H
