//
// Created by Sefi on 12/12/2017.
//

#ifndef EX2_CPP_SEFI_SOLDIER_H
#define EX2_CPP_SEFI_SOLDIER_H

#include <iostream>
#include "Point.h"
#include "Weapon.h"

class Soldier {

    size_t _hp;
    double _speed;
    const int _army;
    Point *_currPosition;
    Point* _nextDestination;
    bool _walking;

protected:

    Soldier(const Point& currPosition, size_t hp, double speed, const int army);

public:

    virtual ~Soldier();

    virtual void attack(Soldier *target)=0;

    void walk();

    virtual void pickObject(CollectableObject *object)=0;

    virtual void dropObject(Point position)=0;

    virtual void defend(double attack)=0;

    virtual const Point getCurrentPosition()=0;

    void setCurrentPosition(Point& newPoint);

    void setNextDestination(const Point& nextPoint);

//    virtual double getHitChance(Soldier *target);

    bool isWalking();
};


#endif //EX2_CPP_SEFI_SOLDIER_H
