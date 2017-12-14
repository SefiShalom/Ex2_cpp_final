//
// Created by Sefi on 12/12/2017.
//

#include "Rifle.h"
#include <iostream>
Rifle::Rifle(Point* position,size_t power,size_t bulletsPerShot):
        Weapon(position,power,bulletsPerShot) {
    std::cout<<"in Rifle ctor"<<std::endl;
}
Rifle::~Rifle(){}