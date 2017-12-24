//
// Created by Sefi on 16/12/2017.
//

#include "BodyArmor.h"
#include "Soldier.h"
BodyArmor::BodyArmor(const Point& position, double defensePower)
        : Armor(position,defensePower){}

BodyArmor::~BodyArmor() {}

double BodyArmor::defend(Weapon *weapon) {
    return weapon->attackArmor(this);
}

void BodyArmor::useObject(Soldier *soldier) {
    soldier->pickObject(this);
}

void BodyArmor::drop(Soldier *soldier) {
    setLocation(soldier->getLocation());
    soldier->set_bodyarmor(nullptr);
}
