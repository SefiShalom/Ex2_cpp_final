//
// Created by Sefi on 20/12/2017.
//

#ifndef EX2_CPP_SEFI_M16_H
#define EX2_CPP_SEFI_M16_H

#include <memory>
#include "Rifle.h"
#include "Fighter.h"

#define M16_POWER 50
#define M16_BULLETSPERSHOT 1

class M16: public Rifle{

public:
    M16(const Point& position);
    ~M16();
    void useObject(Fighter* soldier);

    void useObject(std::shared_ptr<Fighter> fighter);
};


#endif //EX2_CPP_SEFI_M16_H
