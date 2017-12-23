//
// Created by Sefi on 06/12/2017.
//

#ifndef EX2_CPP_POINT_H
#define EX2_CPP_POINT_H

#include <cmath>
#include <iostream>
#define OUT_OF_RANGE -1

class Point {
    double _x,_y;
public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    ~Point();
    double get_x() const;
    double get_y() const;
    void set_x(double x);
    void set_y(double y);
    double distance(Point other);
    bool operator==(const Point& other);
    double getIncline(const Point& dest);
    Point nextPoint(double distance, const Point& dest);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif //EX2_CPP_POINT_H
