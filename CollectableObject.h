//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_COLLECTABLEOBJECT_H
#define EX2_CPP_COLLECTABLEOBJECT_H

#include "MapObject.h"

class Soldier;

class CollectableObject : public MapObject{
    bool _isCarried;

public:
    CollectableObject(Point* position);
    virtual ~CollectableObject();
    void setCurrentPosition(Point* pos);
    void setCarried(bool is);
    virtual void drop(Soldier* soldier) = 0;
    bool isCarried();
    virtual void useObject(Soldier* soldier)=0;
};


#endif //EX2_CPP_COLLECTABLEOBJECT_H
