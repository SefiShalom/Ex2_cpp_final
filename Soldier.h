//
// Created by Sefi on 12/12/2017.
//

#ifndef EX2_CPP_SEFI_SOLDIER_H
#define EX2_CPP_SEFI_SOLDIER_H

#include <iostream>
#include <vector>
#include "Point.h"

//#include "Weapon.h"
//#include "BodyArmor.h"
//#include "ShieldArmor.h"

//class CollectableObject;
class Weapon;
class ShieldArmor;
class BodyArmor;

class Soldier {

    friend class Player;
    friend class Medic;


    size_t _hp, _init_hp;
    double _speed;
    const int _army;
    Point *_currPosition;
    Point* _nextDestination;
    // We should think about switching to independent soldiers:
    std::vector<Point> allDestinations;
    size_t currDestination;
    bool _walking;

    BodyArmor* _bodyarmor;
    ShieldArmor* _shield;
    Weapon* _weapon;

    // For Medic
    void healMe();

    // For Player
    void feedMeWithDestinations(std::vector<Point> points);

    // For CollectableObject handling
//    void setPickedObject(CollectableObject* col, CollectableObject* curr);

protected:

    Soldier(const Point& currPosition, size_t hp, double speed, const int army);

public:

    virtual ~Soldier();

    virtual void attack(Soldier *target)=0;

    void walk();

//    virtual void pickObject(CollectableObject *object)=0;

    virtual void dropObject(Point position)=0;

    virtual void defend(Weapon* weapon)=0;

    virtual const Point getCurrentPosition()=0;

    void setCurrentPosition(Point& newPoint);

    void setNextDestination(const Point& nextPoint);

   virtual void pickObject(BodyArmor* ba)=0;

    virtual void pickObject(ShieldArmor* sa)=0;

    virtual void pickObject(Weapon* weapon)=0;

//    void dropCollectable(CollectableObject* col);

//    virtual double getHitChance(Soldier *target);

    bool isWalking();

    const int getArmy() const;
    friend std::ostream& operator<<(std::ostream& os, const Soldier& soldier);

};


#endif //EX2_CPP_SEFI_SOLDIER_H
