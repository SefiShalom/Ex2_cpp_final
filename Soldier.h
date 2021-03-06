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
#include "SoldierStrategy.h"
//////END

class Weapon;
class Fists;
class SoldierStrategy;
//class ShieldArmor;
//class BodyArmor;

class Soldier: public MapObject {

    friend class Game;
    friend class Player;
    friend class HumanPlayer;
    friend class Medic;


protected:
    double _hp;
    double _speed;
    const short _army;
    Point _nextDestination;
    int currDestinationIndex;
    // We should think about switching to independent soldiers:
    std::vector<Point> allDestinations;

    bool _walking;
    bool _isAlive;
    bool _isBypassingSolidObject;

    // For Medic
    virtual void healMe() = 0;

    // For Player
    void feedMeWithDestinations(std::vector<Point> points);

    // For CollectableObject handling


    Soldier(const Point& currPosition, double hp, double speed, const short army);

    //collectable object pointers
    Weapon* _weapon;
    BodyArmor* _bodyarmor;
    ShieldArmor* _shield;

    virtual void walk(double speed);

public:

    virtual ~Soldier();

    virtual bool attack(Soldier* target) = 0;

    virtual void walk() = 0;

    virtual double getHP() const;

    virtual bool defend(Weapon* weapon);

    bool reduceHP(double hp);

    void refillHP(double refill);

    void setNextDestination(const Point& nextPoint);

    virtual void pickObject(BodyArmor* ba);

    virtual void pickObject(ShieldArmor* sa);

    bool isWalking();

    bool isAlive();

    const int getArmy() const;

    void set_bodyarmor(BodyArmor* bodyarmor);

    void set_shield(ShieldArmor* shield);

    std::vector<SolidObject*> retrieveSolidObjectsInRadius(Game* game);

    void acceptAction(Soldier* soldier);

    void performAction(ShieldArmor* shield);

    void performAction(BodyArmor* bodyarmor);

    virtual void performAction(Weapon* weapon) = 0;

    virtual void performAction(Soldier* soldier) = 0;

    void performAction(SolidObject* solidObject);

    Weapon *get_weapon() const;

    BodyArmor *get_bodyarmor() const;

    ShieldArmor *get_shield() const;

    bool loadNextDest();

    std::ostream& info(std::ostream& os);

    virtual SoldierStrategy* getStrategy() = 0;

    void setIsBypassingSolidObject(bool is);

    bool isBypassingSolidObject();

};


#endif //EX2_CPP_SEFI_SOLDIER_H
