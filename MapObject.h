//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_OBJECT_H
#define EX2_CPP_OBJECT_H

#include "Point.h"



class MapObject {

protected:
    Point _position;
public:
    explicit MapObject(const Point& position);
    virtual ~MapObject() = 0;
    const Point& getLocation() const;
    void setLocation(const Point& newPoint);

};

#endif //EX2_CPP_OBJECT_H
