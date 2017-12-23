//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_COLLECTABLEOBJECT_H
#define EX2_CPP_COLLECTABLEOBJECT_H

#include "Object.h"

class Soldier;

class CollectableObject : public Object{
    bool _isCarried;

public:
    CollectableObject(Point* position);
    virtual ~CollectableObject();
    void setCurrentPosition(Point* pos);
    void setCarried(bool is);
    void drop(Point* pos);
    bool isCarried();
    virtual void useObject(Soldier* soldier)=0;
};


#endif //EX2_CPP_COLLECTABLEOBJECT_H
