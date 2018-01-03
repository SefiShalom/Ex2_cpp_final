//
// Created by damir on 16-Dec-17.
//

#ifndef EX2_CPP_SEFI_MEDIC_H
#define EX2_CPP_SEFI_MEDIC_H

#include <memory>
#include "Soldier.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "Fists.h"

#define MEDIC_HP 120
#define MEDIC_SPEED 4

class Medic : public Soldier {



public:

    //ctor. receives the initial position initial HP soldier's speed (a length of a step)
    //and the army num
    Medic(const Point& position, const short army);

    //dtor
    virtual ~Medic();

    //Perform a healing action on the given soldier
    void heal(Soldier* injured);

    //receives a soldier to attack and uses only Fists
    virtual bool attack(Soldier *target);

    //Invoked when another Medic performs a healing action on the soldier
    void healMe();

    //Passes the MEDIC_SPEED value to the generic walk(double speed) method at Soldier
    void walk();

    //Both performAction functions are part of the implementation of the Visitors design pattern.
    // Represent the 'Visitor' class's visit(Visited*)
    void performAction(Soldier* soldier);
    void performAction(Weapon* weapon);


    //Returns an ostream containing a short description of the instance
    std::ostream& toString (std::ostream& out);

    //Returns the type (name) of the class
    virtual std::string getType();

};


#endif //EX2_CPP_SEFI_MEDIC_H
