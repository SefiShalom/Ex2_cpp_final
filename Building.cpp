//
// Created by Sefi on 30/12/2017.
//

#include "Building.h"

Building::Building(const Point &position)
        : SolidObject(position,BUILDING_LENGTH,BUILDING_WIDTH) {

}

Building::~Building() {

}

std::ostream &Building::toString(std::ostream &out) {
    out<< "Building:" <<std::endl;
    out<< "Location: " << getLocation() <<std::endl;
    out<< "Length: " << getLength() <<std::endl;
    out<< "Width: " << getWidth() <<std::endl;
    return out;
}

std::string Building::getType() {
    return "Building";
}
