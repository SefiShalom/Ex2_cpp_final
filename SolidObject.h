//
// Created by damir on 12-Dec-17.
//

#ifndef EX2_CPP_SOLIDOBJECT_H
#define EX2_CPP_SOLIDOBJECT_H

#include <vector>
#include "Point.h"
#include "MapObject.h"

#define EQUATION_X1 0
#define EQUATION_Y1 1
#define EQUATION_X2 2
#define EQUATION_Y2 3
#define LIMITS_SIZE 4

class SolidObject : public MapObject {

    double _length, _width;
    double _limits[LIMITS_SIZE];

public:

    //  Ctor which receives a point, height and width.
    SolidObject(const Point &position, double len, double width);

    virtual ~SolidObject();

    //  Returns the height of the solid object
    double getLength();

    //  Returns the width of the solid object
    double getWidth();

    //  For Visitor purposes
    virtual void acceptAction(Soldier *soldier);

    //  Checks if this SolidObject is placed between source and destination
    bool isBetween(const Point &source, const Point &destination);

    //  Checks if the given point is inside this SolidObjects
    bool isPointInside(const Point &point);

    //  For printing.
    virtual std::ostream &toString(std::ostream &out);

    //  Generates a bypass point so the soldier would be able to find another way around this SolidObject
    Point getClosestBypassPoint(const Point &source);

    //  Helps "getClosestBypassPoint" by finding the vertices of this rectangular SolidObject
    std::vector<Point> getLimitsPoints();

    //  For Output class.
    virtual std::string getType();

};


#endif //EX2_CPP_SOLIDOBJECT_H
