//
// Created by damir on 12-Dec-17.
//

#include "SolidObject.h"
#include "Soldier.h"

SolidObject::SolidObject(const Point &position, double len, double width)
        : MapObject(position), _length(len>= width?len:width), _width(width<=len?width:len) {

    _limits[EQX1] = getLocation().get_x();
    _limits[EQY1] = getLocation().get_y();
    _limits[EQX2] = getLocation().get_x() + _width;
    _limits[EQY2] = getLocation().get_y() + _length;
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

double *SolidObject::getLimits() {
    return _limits;
}

