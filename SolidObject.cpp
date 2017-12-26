//
// Created by damir on 12-Dec-17.
//

#include "SolidObject.h"
#include "Soldier.h"

SolidObject::SolidObject(const Point& position, double len, double width)
        : MapObject(position), _length(len), _width(width) {
    std::cout<<"in SolidObject ctor"<<std::endl;

}

SolidObject::~SolidObject() {std::cout << "SolidObject dtor" << std::endl;}

void SolidObject::acceptAction(Soldier* soldier) {
    soldier->performAction(this);
}

