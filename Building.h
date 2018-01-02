//
// Created by Sefi on 30/12/2017.
//

#ifndef EX2_CPP_SEFI_BUILDING_H
#define EX2_CPP_SEFI_BUILDING_H


#include "SolidObject.h"

#define BUILDING_LENGTH 3
#define BUILDING_WIDTH 3


class Building: public SolidObject {
    Building(const Point& position);
    ~Building();
    std::ostream& toString(std::ostream& out);
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_BUILDING_H
