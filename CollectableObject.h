//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_COLLECTABLEOBJECT_H
#define EX2_CPP_COLLECTABLEOBJECT_H

#include "Object.h"
//#include "Soldier.h"


    class Soldier;


class CollectableObject : public Object{
    bool _isCarried;

public:
    CollectableObject(Point* position);
    virtual ~CollectableObject();
    virtual void useObject(Soldier* soldier);
    void setCurrentPosition(const Point& pos);
    void setCarried(bool is);
    bool isCarried();
};


#endif //EX2_CPP_COLLECTABLEOBJECT_H
