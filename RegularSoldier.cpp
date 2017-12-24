//
// Created by Sefi on 24/12/2017.
//

#include "RegularSoldier.h"

RegularSoldier::RegularSoldier(Point *currPosition, const short army)
        : Fighter(currPosition,REGULAR_SOLDIER_HP,REGULAR_SOLDIER_SPEED,army){}

void RegularSoldier::healMe() {
    _hp = REGULAR_SOLDIER_HP;
}

RegularSoldier::~RegularSoldier() {std::cout << "RegularSoldier dtor" << std::endl;}

