//
// Created by Sefi on 20/12/2017.
//

#ifndef EX2_CPP_SEFI_M16_H
#define EX2_CPP_SEFI_M16_H


#include "Rifle.h"
#include "Soldier.h"

#define M16_POWER 50
#define M16_BULLETSPERSHOT 1

class M16: public Rifle{

public:
    M16(Point* position);
    ~M16();
    void useObject(Soldier* soldier);
};


#endif //EX2_CPP_SEFI_M16_H
