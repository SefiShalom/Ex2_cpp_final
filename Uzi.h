//
// Created by Sefi on 26/12/2017.
//

#ifndef EX2_CPP_SEFI_UZI_H
#define EX2_CPP_SEFI_UZI_H

#include "Rifle.h"
#include "Fighter.h"

#define UZI_POWER 40
#define UZI_BULLETS_PER_SHOT 3

class Uzi: public Rifle{
    Uzi(const Point& position);
    ~Uzi();
    void useObject(Fighter* fighter);
    void useObject(std::shared_ptr<Fighter> fighter);
};


#endif //EX2_CPP_SEFI_UZI_H