//
// Created by Sefi on 30/12/2017.
//

#ifndef EX2_CPP_SEFI_BUILDING_H
#define EX2_CPP_SEFI_BUILDING_H


#include "SolidObject.h"

#define BUILDING_LENGTH 3
#define BUILDING_WIDTH 3


class Building: public SolidObject {
    // a derived class of SolidObject. Considered as a 3X3 rectangle
    Building(const Point& position);//ctor
    ~Building();//dtor
    std::ostream& toString(std::ostream& out);//returns an ostreaqm object containing a short description if the Building
    virtual std::string getType();//returns the type (name) of the class Building
};


#endif //EX2_CPP_SEFI_BUILDING_H
