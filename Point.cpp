//
// Created by Sefi on 06/12/2017.
//

#include "Point.h"
#include <iostream>

Point::Point() : _x(0), _y(0) {}
Point::Point(double x, double y): _x(x),_y(y) {}
Point::Point(const Point& other): _x(other._x),_y(other._y){}
Point::~Point(){}
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

Point Point::nextPoint(size_t speed, const Point &dest) {
//    speed = pow(speed,2);

    double m = getIncline(dest);
    double a = pow(m,2) + 1;
    double b = 2*_x - 2*m*m*_x-4*_y*m;
    double c = 4*_y*_y + 4*_y*m*_x + m*m*_x*_x+_x*_x - speed*speed;
    double x1 = (-b+sqrt(b*b -4*a*c))/(2*a);
    double x2 = (-b-sqrt(b*b -4*a*c))/(2*a);

//    double y = m*(_x - x1) + _y;
    std::cout<< m <<std::endl;
    std::cout<< a <<std::endl;
    std::cout<< b <<std::endl;
    std::cout<< c <<std::endl;
    std::cout<< x1 <<std::endl;
    std::cout<< x2 <<std::endl;
    return dest._x >= _x ? Point(x1, -(m*(_x - x1) + _y)) : Point(x2, -(m*(_x - x2) + _y));
}
