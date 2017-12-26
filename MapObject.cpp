//
// Created by Sefi on 06/12/2017.
//

#include "MapObject.h"


MapObject::MapObject(const Point& position): _position(position){}

MapObject::~MapObject(){
//    std::cout << "MapObject dtor" << std::endl;
}

const Point& MapObject::getLocation() const {return _position;}

void MapObject::setLocation(const Point &newPoint) {
    _position = newPoint;
}




