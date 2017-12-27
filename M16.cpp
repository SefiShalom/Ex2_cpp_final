//
// Created by Sefi on 20/12/2017.
//

#include "M16.h"


M16::M16(const Point& position)
        :Rifle(position,M16_POWER,M16_BULLETSPERSHOT){}

 M16::~M16(){}

void M16::useObject(Fighter *fighter) {
    fighter->pickObject(this);
}

std::ostream &M16::toString(std::ostream &out) {
    out<< "M16:" <<std::endl;
    out << "Location: " << getLocation() <<std::endl;
    out<< "Power: " << getPower() <<std::endl;
    out<< "Bullets per shot: " << M16_BULLETSPERSHOT <<std::endl;
    return out;
}
