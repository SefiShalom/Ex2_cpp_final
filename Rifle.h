//
// Created by Sefi on 12/12/2017.
//

#ifndef EX2_CPP_SEFI_RIFLE_H
#define EX2_CPP_SEFI_RIFLE_H

#include <memory>

#include "Weapon.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"

//An abstract derived class of class Weapon. Represents 'light' weapons
class Rifle: public Weapon {

 public:

    //ctor. Receives a point, shooting power and bullets per shot.
    Rifle(const Point& position,size_t power,size_t bulletsPerShot);

    //  Virtual dtor. Self explanatory.
    virtual ~Rifle() = 0;

    //Both methods are part of the implementation of the
    // Visitor design pattern (visit(Visited*)).
    //Each one perfoms a different action on the given armor
    double attackArmor(ShieldArmor* sheild);
    double attackArmor(BodyArmor* bodyarmor);

    //drops the instance in the given fighter's current position
    virtual void drop(Fighter* figter);

    //returns true. Rifle instance is a fire arm
    virtual bool isFireArm();
};


#endif //EX2_CPP_SEFI_RIFLE_H
