//
// Created by Sefi on 12/12/2017.
//

#ifndef EX2_CPP_SEFI_SOLDIER_H
#define EX2_CPP_SEFI_SOLDIER_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "MapObject.h"


class Weapon;
class ShieldArmor;
class BodyArmor;

class Soldier: public MapObject {

    friend class Player;
    friend class Medic;


    double _hp;
    double _speed;
    const short _army;
    Point* _nextDestination;
    // We should think about switching to independent soldiers:
    std::vector<Point*> allDestinations;

    bool _walking;

    // For Medic
    virtual void healMe() = 0;

    // For Player
    void feedMeWithDestinations(std::vector<Point*> points);

    // For CollectableObject handling


protected:

    Soldier(Point* currPosition, double hp, double speed, const short army);

    //collectable object pointers
    BodyArmor* _bodyarmor;
    ShieldArmor* _shield;
    Weapon* _weapon;

public:

    virtual ~Soldier();

    virtual void attack(Soldier *target)=0;

    void walk();

//    virtual void pickObject(CollectableObject *object)=0;


    virtual void defend(Weapon* weapon);

    void reduceHP(double hp);

    void refillHP(double refill);

    void setCurrentPosition(Point* newPoint);

    void setNextDestination(Point* nextPoint);

   virtual void pickObject(BodyArmor* ba)=0;

    virtual void pickObject(ShieldArmor* sa)=0;

    virtual void pickObject(Weapon* weapon)=0;

//    void dropCollectable(CollectableObject* col);

//    virtual double getHitChance(Soldier *target);

    bool isWalking();

    const int getArmy() const;

    void set_bodyarmor(BodyArmor* bodyarmor);

    void set_shield(ShieldArmor* shield);

//    void set_weapon(Weapon* weapon);

    friend std::ostream& operator<<(std::ostream& os, const Soldier& soldier);

};


#endif //EX2_CPP_SEFI_SOLDIER_H
