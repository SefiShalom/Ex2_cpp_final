//
// Created by Sefi on 16/12/2017.
//

#include "SheildArmor.h"

SheildArmor::SheildArmor(Point *position, double defensePower)
        : Armor(position,defensePower){}

SheildArmor::~SheildArmor() {

}

double SheildArmor::defend(Weapon *weapon) {
    return weapon->attackArmor(this);
}
