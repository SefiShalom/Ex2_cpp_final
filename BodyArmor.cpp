//
// Created by Sefi on 16/12/2017.
//

#include "BodyArmor.h"


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
}

void BodyArmor::acceptAction(Soldier* soldier) {
    soldier->performAction(this);
}

std::ostream& BodyArmor::toString(std::ostream& out){
//    out << "BodyArmor:\nPoint: " << getLocation() <<
//       "\nDefense Power: "<< getDefensePower() << std::endl;
    double x = getLocation().get_x();
    double y = getLocation().get_y();
    out << "BA(" << getDefensePower() << ")(" << x << "," << y << ")";
    return out;
}
