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

double SolidObject::getLength() {
    return _length;
}

double SolidObject::getWidth() {
    return _width;
}

std::ostream &SolidObject::toString(std::ostream &out) {
    //TODO
    return out;
}

std::string SolidObject::getType() {
    return "SolidObject";
}
