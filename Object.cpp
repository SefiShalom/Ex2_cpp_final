//
// Created by Sefi on 06/12/2017.
//

#include "Object.h"
Object::Object(Point* position): _position(position){}
Object::~Object(){}
const Point Object::getPosition() const {return Point(*_position);}
