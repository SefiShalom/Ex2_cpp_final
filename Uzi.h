//
// Created by Sefi on 26/12/2017.
//

#ifndef EX2_CPP_SEFI_UZI_H
#define EX2_CPP_SEFI_UZI_H

#include "Rifle.h"
#include "Fighter.h"

#define UZI_POWER 40
#define UZI_BULLETS_PER_SHOT 3

class Uzi : public Rifle {

public:

    //  Ctor which receives a point.
    Uzi(const Point &position);

    ~Uzi();

    //  For Visitor purposes. Every fighter is supposed to know what to do with it
    void useObject(Fighter *fighter);

    //  For printing.
    std::ostream &toString(std::ostream &out);

    //  For Output class.
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_UZI_H
