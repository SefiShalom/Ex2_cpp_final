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
//A derived class of Rifle.
//Represents M16 weapon
//Has its own power and bullets per shot

public:
    //ctor. Only receives the initial position of the instance
    M16(const Point& position);

    //dtor
    ~M16();

    //for visitor purposes
    void useObject(Fighter* fighter);

    //Returns an ostream containing a short description of the instance
    std::ostream& toString(std::ostream& out);

    //Returns the type (name) of the class
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_M16_H
