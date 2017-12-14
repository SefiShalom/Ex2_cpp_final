//
// Created by Sefi on 06/12/2017.
//



#ifndef EX2_CPP_COLLECTABLEOBJECT_H
#define EX2_CPP_COLLECTABLEOBJECT_H

#include "Object.h"

class CollectableObject : public Object{

    bool _isCarried;

public:
    CollectableObject(Point* position);
    virtual ~CollectableObject();
    bool isCarried();
};


#endif //EX2_CPP_COLLECTABLEOBJECT_H
