//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_OBJECT_H
#define EX2_CPP_OBJECT_H

#include "Point.h"
#include <memory>

class Soldier;

class MapObject {


protected:
    Point _position;
public:
    explicit MapObject(const Point& position);

    virtual ~MapObject() = 0;

    const Point& getLocation() const;

    void setLocation(const Point& newPoint);

    virtual void acceptAction(Soldier* soldier) = 0;

    virtual std::ostream& toString(std::ostream& out) = 0;

    friend std::ostream& operator << (std::ostream& out,MapObject& object);

};

#endif //EX2_CPP_OBJECT_H
