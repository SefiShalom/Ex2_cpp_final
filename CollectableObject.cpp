//
// Created by Sefi on 08/12/2017.
//

#include "CollectableObject.h"
#include "Soldier.h"

CollectableObject::CollectableObject(const Point& position):
        MapObject(position),_isCarried(false){}

CollectableObject::~CollectableObject(){
//    std::cout << "CollectableObject dtor" << std::endl;
}

bool CollectableObject::isCarried() {
    return _isCarried;
}


void CollectableObject::setCarried(bool is) {
    _isCarried = is;
}

void CollectableObject::drop(Soldier *soldier) {
    setLocation(soldier->getLocation());
}



