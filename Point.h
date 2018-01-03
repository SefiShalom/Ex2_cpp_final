//
// Created by Sefi on 06/12/2017.
//

#ifndef EX2_CPP_POINT_H
#define EX2_CPP_POINT_H

#include <cmath>
#include <limits>
#include <iostream>

#define OUT_OF_RANGE -INFINITY
#define UNREACHABLE_POINT Point(OUT_OF_RANGE,OUT_OF_RANGE)

//Represents a point in a 2 dimension field

class Point {

    //Coordinates
    double _x,_y;

public:

    //default ctor. creates a point in (0,0)
    Point();

    //ctor. creates a point in (x,y)
    Point(double x, double y);

    //copy ctor.
    Point(const Point& other);

    //dtor
    ~Point();

    //returns the X coordinates value
    double get_x() const;

    //returns the Y coordinates value
    double get_y() const;

    //sets the X coordinates to the given value
    void set_x(double x);

    //sets the Y coordinates to the given value
    void set_y(double y);

    //Calculates the distance between the Point instance and a another Pint instance
    double distance(const Point& other) const;

    //Returns true if both X and Y coordinates of the Point instance and the  given
    //point are equal. Returns false otherwise
    bool operator==(const Point& other);

    //Calculates the incline between the Point instance and the given
    //point
    double getIncline(const Point& dest) const;

    //Returns the next point in the given distance from the Point instance
    //on the line between the Point instance and the destination
    //used to calculate the next point to which a soldier will get on it's next step
    //on the way to it's destination
    Point nextPoint(double distance, const Point& dest) const;

    //Operator '='. Copies the other point coordinates
    // values into it's own coordinates
    Point& operator=(const Point& other);

    //Returns false is X or Y coordinate is OUT_OF_RANGE
    bool isReachable();

    //Enables out streaming for an instance of a point
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif //EX2_CPP_POINT_H
