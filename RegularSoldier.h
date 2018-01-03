//
// Created by Sefi on 24/12/2017.
//

#ifndef EX2_CPP_SEFI_REGULARSOLDIER_H
#define EX2_CPP_SEFI_REGULARSOLDIER_H


#include "Fighter.h"

#define REGULAR_SOLDIER_HP 100
#define REGULAR_SOLDIER_SPEED 2
#define REGULAR_SOLDIER_RUNNING_SPEED 4

class RegularSoldier: public Fighter {



    ////Invokes the Soldier class walk(double speed) method with REGULAR_SOLDIER_RUNNING_SPEED
    //Reduces 10 HP. Invokes when the next destination is 4 times REGULAR_SOLDIER_SPEED further from the current location
    virtual void run();

public:

    //ctor. receives the initial position and the army num
    RegularSoldier(const Point& position, const short army);

    //dtor
    virtual ~RegularSoldier();

    //Invoked when a Medic performs a healing action on the soldier
    void healMe();


    //Calculates the chance to hit the enemy. Probability is 1 / the distance between the two
    virtual double calculateHitChance(Soldier *enemy) const;

    //Invokes the Soldier class walk(double speed) method with REGULAR_SOLDIER_SPEED
    virtual void walk();

    //Returns an ostream instance containing a short description of the instance
    std::ostream& toString (std::ostream& out);

    //returns he type (name) of the class
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_REGULARSOLDIER_H
