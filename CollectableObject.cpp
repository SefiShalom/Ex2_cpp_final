//
// Created by Sefi on 08/12/2017.
//

#include "CollectableObject.h"

CollectableObject::CollectableObject(Point* position):
        Object(position),_isCarried(false){}

CollectableObject::~CollectableObject(){}

bool CollectableObject::isCarried() {
    return _isCarried;
}

void CollectableObject::setCurrentPosition(Point* pos) {
    std::cout << "in setCurrPosition" << std::endl;
    if (_position) {
        delete _position;
    }else{
        std::cout << "_position is not nullptr" << std::endl;
        _position = pos;
    }
}

void CollectableObject::setCarried(bool is) {
    _isCarried = is;
}

void CollectableObject::drop(Point* pos) {
    setCurrentPosition(pos);
    setCarried(false);
}

