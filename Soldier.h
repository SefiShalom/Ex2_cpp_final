//
// Created by Sefi on 12/12/2017.
//

#ifndef EX2_CPP_SEFI_SOLDIER_H
#define EX2_CPP_SEFI_SOLDIER_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "MapObject.h"
//////NEW
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "SolidObject.h"
//////END

class Weapon;
//class ShieldArmor;
//class BodyArmor;

class Soldier: public MapObject {

    friend class Player;
    friend class HumanPlayer;
    friend class Medic;

protected:
    double _hp;
    double _speed;
    const short _army;
    Point _nextDestination;
    // We should think about switching to independent soldiers:
    std::vector<Point*> allDestinations;

    bool _walking;



    // For Medic
    virtual void healMe() = 0;

    // For Player
    void feedMeWithDestinations(std::vector<Point*> points);

    // For CollectableObject handling


    Soldier(const Point& currPosition, double hp, double speed, const short army);

    //collectable object pointers
    BodyArmor* _bodyarmor;
    ShieldArmor* _shield;
    std::shared_ptr<BodyArmor> __bodyarmor;
    std::shared_ptr<ShieldArmor> __shield;

    virtual void walk(double speed);

public:

    virtual ~Soldier();

    virtual void attack(Soldier* target) = 0;

    virtual void walk() = 0;

    virtual double getHP() const;

    virtual void defend(Weapon* weapon);

    void reduceHP(double hp);

    void refillHP(double refill);

    void setNextDestination(const Point& nextPoint);

    virtual void pickObject(BodyArmor* ba)=0;

    virtual void pickObject(ShieldArmor* sa)=0;

    bool isWalking();

    const int getArmy() const;

    void set_bodyarmor(BodyArmor* bodyarmor);

    void set_shield(ShieldArmor* shield);


    friend std::ostream& operator<<(std::ostream& os, const Soldier& soldier);

    std::vector<MapObject> scanRadius();

    void acceptAction(Soldier* soldier);

    void performAction(ShieldArmor* shield);
    void performAction(BodyArmor* bodyarmor);
    virtual void performAction(Soldier* soldier) = 0;
    void performAction(Weapon* weapon);
    void performAction(SolidObject* solidObject);


};


#endif //EX2_CPP_SEFI_SOLDIER_H
