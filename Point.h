//
// Created by Sefi on 06/12/2017.
//

#ifndef EX2_CPP_POINT_H
#define EX2_CPP_POINT_H

#include <cmath>
#include <iostream>
#define OUT_OF_RANGE -1
#define UNREACHABLE_POINT Point(OUT_OF_RANGE,OUT_OF_RANGE)

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
    double distance(const Point& other) const;
    bool operator==(const Point& other);
    double getIncline(const Point& dest) const;
    Point nextPoint(double distance, const Point& dest) const;
    Point& operator=(const Point& other);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif //EX2_CPP_POINT_H
