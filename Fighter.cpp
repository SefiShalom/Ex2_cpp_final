//
// Created by damir on 19-Dec-17.
//

#include "Fighter.h"

Fighter::Fighter(const Point &currPosition, size_t hp, double speed, const int army)
        : Soldier(currPosition, hp, speed, army) {}

void Fighter::attack(Soldier *target) {
//    target->defend()
}

