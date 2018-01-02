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

    SolidObject(const Point &position, double len, double width);

    virtual ~SolidObject();

    double getLength();

    double getWidth();

    virtual void acceptAction(Soldier *soldier);

    bool isBetween(const Point &source, const Point &destination);

    bool isPointInside(const Point &point);

    virtual std::ostream &toString(std::ostream &out);

    Point getClosestBypassPoint(const Point &source);

    std::vector<Point> getLimitsPoints();

    virtual std::string getType();

};


#endif //EX2_CPP_SOLIDOBJECT_H
