//
// Created by damir on 19-Dec-17.
//

#ifndef EX2_CPP_SEFI_FISTS_H
#define EX2_CPP_SEFI_FISTS_H


#include "Weapon.h"

#define FISTS_POWER 10
#define BULLETS_PER_SHOT 1


class Fists : public Weapon {

public:
    Fists(Point *position, size_t power, size_t bulletsPerShot);


};


#endif //EX2_CPP_SEFI_FISTS_H
