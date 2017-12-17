//
// Created by Sefi on 17/12/2017.
//

#include "Missile.h"
#include <iostream>

Missile::Missile(Point* position,size_t power,size_t bulletsPerShot)
        :Weapon(position,power,bulletsPerShot) {
    std::cout<<"in Missile ctor"<<std::endl;
}
Missile::~Missile(){}

double Missile::attackArmor(BodyArmor* bodyarmor) {
    std::cout << "Missile attacked BodyArmor: NOT_AFFECTED_BY_BODYARMOR" << std::endl;
    return shoot()*NOT_AFFECTED_BY_BODYARMOR;
}

double Missile::attackArmor(ShieldArmor *sheild) {
    std::cout << "Missile attacked ShieldArmor: ShieldArmor has reduced the attack to " <<
              shoot()*(sheild->getDefensePower())<< std::endl;
    return shoot()*(sheild->getDefensePower());
}
