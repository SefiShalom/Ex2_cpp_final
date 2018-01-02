//
// Created by damir on 12-Dec-17.
//

#include <strings.h>
#include "SolidObject.h"
#include "Soldier.h"

SolidObject::SolidObject(const Point &position, double len, double width)
        : MapObject(position), _length(len>= width?len:width), _width(width<=len?width:len) {

    _limits[EQUATION_X1] = getLocation().get_x();
    _limits[EQUATION_Y1] = getLocation().get_y();
    _limits[EQUATION_X2] = getLocation().get_x() + _width;
    _limits[EQUATION_Y2] = getLocation().get_y() + _length;
}

SolidObject::~SolidObject() {}

void SolidObject::acceptAction(Soldier *soldier) {
    soldier->performAction(this);
}

double SolidObject::getLength() {
    return _length;
}

double SolidObject::getWidth() {
    return _width;
}

std::ostream &SolidObject::toString(std::ostream &out) {
    //TODO
    return out;
}

std::string SolidObject::getType() {
    return "SolidObject";
}


bool SolidObject::isBetween(const Point& source, const Point &destination) {

    if(source.distance(destination) < source.distance(getLocation())) return false;

    double sourceX = source.get_x();
    double sourceY = source.get_y();

    Point p;

    double m = source.getIncline(destination);

    for (int i = 0; i < LIMITS_SIZE; ++i) {

        if (!(i % 2)) p = Point(_limits[i],m*(_limits[i]-sourceX)+sourceY);

        else  p = Point((sourceY-m*sourceX-_limits[i])/m,_limits[i]);

        if(m == source.getIncline(p)) return true;

        }

    return false;

    }

bool SolidObject::isPointInside(const Point &point) {
    return (point.get_x() >= getLocation().get_x()) &&
            (point.get_x() <= getLocation().get_x()+_width)&&
            (point.get_y() >= getLocation().get_y())&&
            (point.get_y() <= getLocation().get_y()+_length);
}



std::vector<Point> SolidObject::getLimitsPoints() {

    std::vector<Point> limitsRet;
    double x = getLocation().get_x();
    double y = getLocation().get_y();

    limitsRet.emplace_back(Point(x-1,y-1));
    limitsRet.emplace_back(Point(x,y+_length+1));
    limitsRet.emplace_back(Point(x+_width,y-1));
    limitsRet.emplace_back(Point(x+_width+1,y+_length+1));

    return limitsRet;
}

Point SolidObject::getClosestBypassPoint(const Point &source) {

    std::vector<Point> limitsPoints = getLimitsPoints();
    double minDist = INFINITY;
    int index;
    Point ret;
    for(auto& it : limitsPoints){
        if(source.distance(it) < minDist){
            minDist = source.distance(it);
            ret = it;
        }
    }
    return ret;
}

