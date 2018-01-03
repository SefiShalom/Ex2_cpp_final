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


//An abstract derived class of MapObject
//Represents a common functionalities and fields of a any Soldier kind in the game

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

    // For Medic. Invoked when a Medic performs healing action on the Soldier
    virtual void healMe() = 0;

    // For Player. Feeds the soldier's points' vector
    void feedMeWithDestinations(std::vector<Point> points);

    //ctor. Recives a point, initial HP, speed (a length of a step) and army num
    Soldier(const Point& currPosition, double hp, double speed, const short army);

    //collectable object pointers
    Weapon* _weapon;
    BodyArmor* _bodyarmor;
    ShieldArmor* _shield;

    //Set the soldier's position to the next point based on the length of the soldier's step
    virtual void walk(double speed);

public:

    //dtor
    virtual ~Soldier();

    //Pure virtual method. Different implementation in every derived class
    //receives the target by a pointer
    virtual bool attack(Soldier* target) = 0;

    //Pure virtual method. Invokes the generic walk(double speed) method
    //with the relevant speed value
    virtual void walk() = 0;

    //returns the current HP of the soldier
    virtual double getHP() const;

    //Reduces the power of the given weapon's attack power
    //Uses the Soldier's BodyArmor and ShieldArmor
    //Returns true if the Soldier's HP has been reduced to or under 0
    virtual bool defend(Weapon* weapon);

    //Substract the given HP from the Soldier's current HP value
    bool reduceHP(double hp);

    // Refills the current HP to the maximum HP.
    //Invoked when a Medic perform a healing action on the Soldier
    void refillHP(double refill);

    //Sets the next desitnation a Soldier should walk to to the given point
    void setNextDestination(const Point& nextPoint);

    //Assigns the the given BodyArmor to the soldier
    virtual void pickObject(BodyArmor* ba);

    //Assigns the the given ShieldArmor to the soldier
    virtual void pickObject(ShieldArmor* sa);

    //Tells if the Soldier is on it's way to some destination
    bool isWalking();

    //Returns the value of _isAlive
    bool isAlive();

    //Return the army num of the Soldier
    const int getArmy() const;

    //sets the _bodyAarmor to the given pointer
    void set_bodyarmor(BodyArmor* bodyarmor);

    //sets the _bodyAarmor to the given pointer
    void set_shield(ShieldArmor* shield);

    //A part of the Visitor design pattern implementation (accept(Visitor*))
    void acceptAction(Soldier* soldier);

    //A part of the Visitor design pattern implementation (visit(Visited*))
    void performAction(ShieldArmor* shield);

    //A part of the Visitor design pattern implementation (visit(Visited*))
    void performAction(BodyArmor* bodyarmor);

    //A part of the Visitor design pattern implementation (visit(Visited*))
    virtual void performAction(Weapon* weapon) = 0;

    //A part of the Visitor design pattern implementation (visit(Visited*))
    virtual void performAction(Soldier* soldier) = 0;

    //A part of the Visitor design pattern implementation (visit(Visited*))
    void performAction(SolidObject* solidObject);

    //Returns the current value of the _weapon of the Soldier
    Weapon *get_weapon() const;

    //Returns the current value of the _bodyarmor of the Soldier
    BodyArmor *get_bodyarmor() const;

    //Returns the current value of the _shield of the Soldier
    ShieldArmor *get_shield() const;

    //Loads the next destination (Point) from the allDestinations vector
    bool loadNextDest();

    // Returns an ostream instance containing an info about the Soldier instance
    std::ostream& info(std::ostream& os);

    //Both methods are used to tell if the soldier is bypassing a solid object
    void setIsBypassingSolidObject(bool is);
    bool isBypassingSolidObject();

};


#endif //EX2_CPP_SEFI_SOLDIER_H
