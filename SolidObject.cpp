//
// Created by damir on 12-Dec-17.
//

#include "SolidObject.h"
#include "Soldier.h"

SolidObject::SolidObject(const Point& position, double len, double width)
        : MapObject(position), _length(len), _width(width) {}

SolidObject::~SolidObject() {}

void SolidObject::acceptAction(Soldier* soldier) {
    soldier->performAction(this);
}

std::ostream &SolidObject::toString(std::ostream &out) {
    out<< "SolidObject:" <<std::endl;
    out<< "Location: " << getLocation() <<std::endl;
    out<< "Length: " << _length <<std::endl;
    out<< "Width: " << _width <<std::endl;
    return out;
}
