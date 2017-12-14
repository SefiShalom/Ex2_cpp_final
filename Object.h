//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_OBJECT_H
#define EX2_CPP_OBJECT_H

#include "Point.h"

class Object {
    Point* _position;
public:
    Object(Point* position);
    virtual ~Object() = 0;
    const Point getPosition() const;
};

#endif //EX2_CPP_OBJECT_H
