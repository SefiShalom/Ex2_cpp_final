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
    CollectableObject(const Point& position);
    virtual ~CollectableObject();
    void setCarried(bool is);
    virtual void drop(Soldier* soldier);
    bool isCarried();
};


#endif //EX2_CPP_COLLECTABLEOBJECT_H
