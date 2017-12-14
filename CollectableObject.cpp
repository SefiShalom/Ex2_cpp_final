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