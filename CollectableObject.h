//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_COLLECTABLEOBJECT_H
#define EX2_CPP_COLLECTABLEOBJECT_H

#include "Object.h"

class CollectableObject : public Object{
//    class Soldier;
    bool _isCarried;
    
public:
    CollectableObject(Point* position);
    virtual ~CollectableObject();
//    virtual void useObject(Soldier* soldier) = 0;
    void setCurrentPosition(const Point& pos);
    void setCarried(bool is);
    bool isCarried();
};


#endif //EX2_CPP_COLLECTABLEOBJECT_H
