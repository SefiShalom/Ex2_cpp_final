//
// Created by Sefi on 06/12/2017.
//

#include "Point.h"
#include <iostream>

Point::Point() : _x(0), _y(0) {}
Point::Point(double x, double y): _x(x),_y(y) {}
Point::Point(const Point& other): _x(other._x),_y(other._y){}
Point::~Point(){std::cout << "deleted Point";}
double Point::get_x() const {return _x;}
double Point::get_y() const {return _y;}
void Point::set_x(double x){_x = x;}
void Point::set_y(double y){_y = y;}
double Point::distance(Point other) {
    return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
}

bool Point::operator==(const Point &other) {
    return _x==other._x && _y==other._y;
}

double Point::getIncline(const Point &other) {
    return (_y-other.get_y())/(_x-other.get_x());
}

Point Point::nextPoint(double distance, const Point &dest) {

    if(_x == dest._x){
        return dest._y > _y ? Point(_x,_y+distance) : Point(_x,_y-distance);
    }

    double m = getIncline(dest);
    double x1 = _x+sqrt(pow(distance,2)/(1+pow(m,2)));
    double x2 = _x-sqrt(pow(distance,2)/(1+pow(m,2)));

    return dest._x >= _x ? Point(x1, (m*(x1-_x) + _y)) : Point(x2, (m*(x2 - _x) + _y));
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(X: " << p.get_x() << ", Y: " << p.get_y() << ")";
    return os;
}
