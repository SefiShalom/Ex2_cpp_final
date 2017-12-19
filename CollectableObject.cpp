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

void CollectableObject::setCurrentPosition(const Point& pos) {
    if (_position != nullptr)
        delete _position;
    _position = new Point(pos);
}

void CollectableObject::setCarried(bool is) {
    _isCarried = is;
}

void CollectableObject::useObject(Soldier *soldier) {



    /////////// GET THIS TO WORK!!!!!!!!!!!!!!!!!!!!!


//    soldier->pickObject(this);
}
