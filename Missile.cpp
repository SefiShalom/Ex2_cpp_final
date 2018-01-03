//
// Created by Sefi on 17/12/2017.
//

#include "Missile.h"
#include <iostream>


Missile::Missile(const Point& position)
        :Weapon(position,MISSILE_POWER,MISSILE_BULLETS_PER_SHOT){}
Missile::~Missile(){
//    std::cout << "Missile dtor" << std::endl;
}

double Missile::attackArmor(BodyArmor* bodyarmor) {
    std::cout << "Missile attacked BodyArmor: NOT_AFFECTED_BY_BODYARMOR" << std::endl;
    return shoot()*NOT_AFFECTED_BY_BODYARMOR;
}

double Missile::attackArmor(ShieldArmor *sheild) {
    std::cout << "Missile attacked ShieldArmor: ShieldArmor has reduced the attack to " <<
              shoot()*(sheild->getDefensePower())<< std::endl;
    return shoot()*(sheild->getDefensePower());
}

void Missile::useObject(Fighter* soldier) {
    soldier->pickObject(this);
}

void Missile::drop(Fighter *soldier) {

}


std::ostream &Missile::toString(std::ostream &out) {

    double x = getLocation().get_x();
    double y = getLocation().get_y();
    out << "Missile" << "(" << x << "," << y << ")";

    return out;
}

bool Missile::isFireArm() {
    return true;
}

std::string Missile::getType() {
    return "Missile";
}

