//
// Created by Sefi on 12/12/2017.
//

#include "Rifle.h"
#include <iostream>

Rifle::Rifle(const Point& position,size_t power,size_t bulletsPerShot)
        :Weapon(position,power,bulletsPerShot) {
}
Rifle::~Rifle(){
//    std::cout << "Rifle dtor" << std::endl;
}

double Rifle::attackArmor(BodyArmor *bodyarmor) {
    std::cout << "Rifle attacking BodyArmor: BodyArmor has reduced the attack to :" <<
              shoot()*(bodyarmor->getDefensePower()) << std::endl;
    return shoot()*(bodyarmor->getDefensePower());
}

double Rifle::attackArmor(ShieldArmor *shield) {
    std::cout << "Rifle attacked ShieldArmor: ShieldArmor has reduced the attack to :" <<
              shoot()*(shield->getDefensePower()) << std::endl;
    return shoot()*(shield->getDefensePower());
}

void Rifle::drop(Fighter *figter) {

}


double Rifle::attackArmor(std::shared_ptr<ShieldArmor> shield) {
    std::cout << "Rifle attacked ShieldArmor: ShieldArmor has reduced the attack to :" <<
              shoot()*(shield->getDefensePower()) << std::endl;
    return shoot()*(shield->getDefensePower());
}

double Rifle::attackArmor(std::shared_ptr<BodyArmor> bodyarmor) {
    std::cout << "Rifle attacking BodyArmor: BodyArmor has reduced the attack to :" <<
              shoot()*(bodyarmor->getDefensePower()) << std::endl;
    return shoot()*(bodyarmor->getDefensePower());
}

void Rifle::drop(std::shared_ptr<Fighter> fighter) {

}
