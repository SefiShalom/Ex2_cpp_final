//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_OBJECT_H
#define EX2_CPP_OBJECT_H

#include "Point.h"
#include <memory>

class Soldier;

class MapObject {
//Abstract class
//Represents an Object on the Game's map. Each object in the game is a MapObject instance

    static long ID;
    const long _id;

protected:
    Point _position;
public:
    explicit MapObject(const Point& position);//ctor. receives an initial point.

    virtual ~MapObject() = 0;//dtor.

    const Point& getLocation() const; // returns the current position of the instance

    void setLocation(const Point& newPoint);//sets the location of the instance to the given point

    //An implementation of the Visitor design pattern.
    //Represent the accept(Visitor*) method.
    //Every MapObject instance can have actions taken on it
    virtual void acceptAction(Soldier* soldier) = 0;

    //Returns an ostream containing a short description of the instance
    virtual std::ostream& toString(std::ostream& out) = 0;

    //Enables streaming to another ostream instance
    friend std::ostream& operator << (std::ostream& out,MapObject& object);

    //Returns the identifier of the instance
    long getID() const;

    //Returns the type (name) of the class
    virtual std::string getType() = 0;
};

#endif //EX2_CPP_OBJECT_H
