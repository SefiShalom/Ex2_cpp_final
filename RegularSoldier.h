//
// Created by Sefi on 24/12/2017.
//

#ifndef EX2_CPP_SEFI_REGULARSOLDIER_H
#define EX2_CPP_SEFI_REGULARSOLDIER_H


#include "Fighter.h"

#define REGULAR_SOLDIER_HP 100
#define REGULAR_SOLDIER_SPEED 2

#define REGULARSOLDIER_WALKING_SPEED 2
class RegularSoldier: public Fighter {

public:
    RegularSoldier(Point* currPosition, const short army);
    virtual ~RegularSoldier();
    void healMe();

};


#endif //EX2_CPP_SEFI_REGULARSOLDIER_H
