//
// Created by damir on 19-Dec-17.
//

#ifndef EX2_CPP_SEFI_FIGHTER_H
#define EX2_CPP_SEFI_FIGHTER_H

#include "Soldier.h"
#include "Fists.h"

class Fighter : public Soldier {
// An abstract derived class of Soldier.
//Represents a Soldier who can have a weapon and can use it to attack

public:

    //ctor. receives the initial position initial HP soldier's speed (a length of a step)
    //and the army num
    Fighter(const Point &position, size_t hp, double speed, const int army);

    //dtor
    virtual ~Fighter();

    //receives a soldier to attack and uses its weapon
    virtual bool attack(Soldier *target);

    //assigns a Weapon instance to the Fighter soldier and changes the weapon instance's position
    virtual void pickObject(Weapon *weapon);

    //set the Weapon pointer to the given instance
    void set_weapon(Weapon *weapon);

    //Abstract method. Implemented differently in each derived class of a Fighter
    //calculates the chance to hit the enemy
    virtual double calculateHitChance(Soldier *enemy) const = 0;

    //Both performAction functions are part of the implementation of the Visitors design pattern.
    // Represent the 'Visitor' class's visit(Visited*)
    void performAction(Soldier* soldier);

    void performAction(Weapon* weapon);

    //generate a random number. used when calculateHitChance(Soldier *enemy) is called.
    float getRandom();
};


#endif //EX2_CPP_SEFI_FIGHTER_H
