//
// Created by Sefi on 26/12/2017.
//

#include "Uzi.h"

Uzi::Uzi(const Point &position)
        :Rifle(position,UZI_POWER,UZI_BULLETS_PER_SHOT){}

Uzi::~Uzi() {}

void Uzi::useObject(Fighter *fighter) {
    fighter->pickObject(this);
}

void Uzi::useObject(std::shared_ptr<Fighter> fighter) {
    fighter->pickObject(this);
}

std::ostream &Uzi::toString(std::ostream& out) {

//    out<< "Uzi:" <<std::endl;
//    out << "Location: " << getLocation() <<std::endl;
//    out<< "Power: " << getPower() <<std::endl;
//    out<< "Bullets per shot: " << UZI_BULLETS_PER_SHOT <<std::endl;

    double x = getLocation().get_x();
    double y = getLocation().get_y();
    out << "Uzi" << "(" << x << "," << y << ")";

    return out;
}