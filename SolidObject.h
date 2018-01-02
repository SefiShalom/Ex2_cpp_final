//
// Created by damir on 12-Dec-17.
//

#ifndef EX2_CPP_SOLIDOBJECT_H
#define EX2_CPP_SOLIDOBJECT_H

#include "Point.h"
#include "MapObject.h"

#define EQX1 0
#define EQY1 1
#define EQX2 2
#define EQY2 3
#define LIMITS_SIZE 4

class SolidObject : public MapObject, public std::enable_shared_from_this<SolidObject> {

    double _length, _width;
    double _limits[4];

public:

    SolidObject(const Point& position, double len, double width);
    virtual ~SolidObject();
    double getLength();
    double getWidth();
    virtual void acceptAction(Soldier* soldier);
    bool isBetween(const Point& source,const Point& destination);
    bool isPointInside(const Point& point);
    virtual std::ostream& toString(std::ostream& out);
    double* getLimits();
};



#endif //EX2_CPP_SOLIDOBJECT_H
