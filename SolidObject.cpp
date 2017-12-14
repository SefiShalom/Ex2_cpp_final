//
// Created by damir on 12-Dec-17.
//

#include "SolidObject.h"
#include <iostream>
SolidObject::SolidObject(Point* position, double len, double width)
        : Object(position), _length(len), _width(width) {
    std::cout<<"in SolidObject ctor"<<std::endl;

}

SolidObject::~SolidObject() {}
