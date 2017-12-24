//
// Created by Sefi on 08/12/2017.
//

#include "CollectableObject.h"

CollectableObject::CollectableObject(Point* position):
        MapObject(position),_isCarried(false){}

CollectableObject::~CollectableObject(){std::cout << "CollectableObject dtor" << std::endl;}

bool CollectableObject::isCarried() {
    return _isCarried;
}

void CollectableObject::setCurrentPosition(Point* pos) {
    if (_position != nullptr)
        delete _position;
    _position = pos;
}

void CollectableObject::setCarried(bool is) {
    _isCarried = is;
}


