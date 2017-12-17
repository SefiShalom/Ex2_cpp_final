//
// Created by Sefi on 17/12/2017.
//

#ifndef EX2_CPP_SEFI_MISSILE_H
#define EX2_CPP_SEFI_MISSILE_H

#include "Weapon.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"

#define NOT_AFFECTED_BY_BODYARMOR 1

class Missile: public Weapon {

    public:
        Missile(Point* position,size_t power,size_t bulletsPerShot);
        virtual ~Missile();
        double attackArmor(ShieldArmor* sheild);
        double attackArmor(BodyArmor* bodyarmor);
};


#endif //EX2_CPP_SEFI_MISSILE_H
