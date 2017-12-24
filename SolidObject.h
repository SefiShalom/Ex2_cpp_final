//
// Created by damir on 12-Dec-17.
//

#ifndef EX2_CPP_SOLIDOBJECT_H
#define EX2_CPP_SOLIDOBJECT_H

#include "Point.h"
#include "MapObject.h"

class SolidObject : public MapObject {

    double _length, _width;
public:

    SolidObject(Point* position, double len, double width);
    virtual ~SolidObject();

};


#endif //EX2_CPP_SOLIDOBJECT_H
