//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_COLLECTABLEOBJECT_H
#define EX2_CPP_COLLECTABLEOBJECT_H

#include "MapObject.h"

class Soldier;

class CollectableObject : public MapObject{

    //A derived class of MapObject
    //Represents an abstract class of objects which a soldier can carry and drop

    bool _isCarried;//determines whether the instance is currently carried by a soldier

public:
    CollectableObject(const Point& position);//ctor. gets the initial position
    virtual ~CollectableObject();//dtor
    void setCarried(bool is);//set the _isCarried flag to the relevant value
    virtual void drop(Soldier* soldier);//drops the CollectableObject in the given soldier's current position
    bool isCarried();//returns the value of _isCarried
};

#endif //EX2_CPP_COLLECTABLEOBJECT_H
