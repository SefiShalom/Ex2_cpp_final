//
// Created by Sefi on 17/12/2017.
//

#ifndef EX2_CPP_SEFI_MISSILE_H
#define EX2_CPP_SEFI_MISSILE_H

#include "Weapon.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "Fighter.h"

#define MISSILE_POWER 100
#define MISSILE_BULLETS_PER_SHOT 1
#define NOT_AFFECTED_BY_BODYARMOR 1

class Missile : public Weapon {
//A derived class of Weapon.
//Represents Missile weapon
//Has its own power and bullets per shot


public:
    //ctor. Only receives the initial position of the instance
    Missile(const Point &position);

    //dtor
    virtual ~Missile();

    //performs an attack on a given shield armor
    double attackArmor(ShieldArmor *sheild);

    //performs an attack on a given body armor
    double attackArmor(BodyArmor *bodyarmor);

    //for Visitor purposes
    void useObject(Fighter *soldier);

    //drops the instance on the given soldier's current position
    void drop(Fighter *soldier);

    //Returns an ostream containing a short description of the instance
    std::ostream& toString(std::ostream& out);

    //returns true. Missile instance is a fire arm
    virtual bool isFireArm();

    //Returns the type (name) of the class
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_MISSILE_H
