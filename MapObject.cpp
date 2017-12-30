//
// Created by Sefi on 06/12/2017.
//

#include "MapObject.h"

long MapObject::ID = 1;

MapObject::MapObject(const Point& position): _id(ID++), _position(position){}

MapObject::~MapObject(){
//    std::cout << "MapObject dtor" << std::endl;
}

const Point& MapObject::getLocation() const {return _position;}

void MapObject::setLocation(const Point &newPoint) {
    _position = newPoint;
}

std::ostream& operator<<(std::ostream &out, MapObject &object) {
    return object.toString(out);
}

long MapObject::getID() const {
    return _id;
}




