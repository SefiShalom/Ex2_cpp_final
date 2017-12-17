//
// Created by Sefi on 16/12/2017.
//

#include "BodyArmor.h"

BodyArmor::BodyArmor(Point* position, double defensePower)
        : Armor(position,defensePower){}

BodyArmor::~BodyArmor() {

}

double BodyArmor::defend(Weapon *weapon) {
    return weapon->attackArmor(this);
}