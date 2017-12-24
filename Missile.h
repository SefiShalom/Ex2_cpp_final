//
// Created by Sefi on 17/12/2017.
//

#ifndef EX2_CPP_SEFI_MISSILE_H
#define EX2_CPP_SEFI_MISSILE_H

#include "Weapon.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "Soldier.h"

#define MISSILE_POWER 100
#define MISSILE_BULLETS_PER_SHOT 1
#define NOT_AFFECTED_BY_BODYARMOR 1

class Missile: public Weapon {

    public:
        Missile(Point* position);
        virtual ~Missile();
        double attackArmor(ShieldArmor* sheild);
        double attackArmor(BodyArmor* bodyarmor);
        void useObject(Soldier* soldier);
};


#endif //EX2_CPP_SEFI_MISSILE_H
