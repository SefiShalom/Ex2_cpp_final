//
// Created by damir on 24-Dec-17.
//

#ifndef EX2_CPP_SEFI_SNIPERSOLDIER_H
#define EX2_CPP_SEFI_SNIPERSOLDIER_H


#include "Fighter.h"

#define SNIPER_SOLDIER_IDENTIFIER 222
#define SNIPER_SOLDIER_HP 80
#define SNIPER_SOLDIER_SPEED 2

class SniperSoldier : public Fighter {

public:
    //ctor. receives the initial position and the army num
    SniperSoldier(const Point &location, short army);

    //dtor
    ~SniperSoldier();

    //Invoked when a Medic performs a healing action on the soldier
    void walk();


    //Invoked when a Medic performs a healing action on the soldier
    void healMe();

    //Calculates the chance to hit the enemy. Probability is
    // the distance between the two - 1 / the distance between the two
    double calculateHitChance(Soldier *enemy) const;

    //Returns an ostream instance containing a short description of the instance
    std::ostream& toString (std::ostream& out);

    //returns he type (name) of the class
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_SNIPERSOLDIER_H
