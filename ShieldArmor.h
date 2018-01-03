//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_SHEILDARMOR_H
#define EX2_CPP_SEFI_SHEILDARMOR_H

#include <memory>

#include "Armor.h"
#include "Weapon.h"
#include "Soldier.h"

class ShieldArmor: public Armor {

    //A derived class of Armor
    //Represents a BodyArmor that a soldier wears upon it's body

public:

    //ctor. gets the initial position and the defense power
    ShieldArmor(const Point& position, double defensePower);

    //dtor
    ~ShieldArmor();

    // reduces the given Weapon attack power by the instance defense power
    double defend(Weapon* weapon);

    // invokes the given soldier 'pickObject' method which assigning the BodyArmor to it.
    void useObject(Soldier* soldier);

    //drops the instance in the given soldier's current position
    void drop(Soldier* soldier);


    // passing the instance to the given Soldier's 'performAction'
    // to perform the relevant action on the instance
    //Visitor purposes
    void acceptAction(Soldier* soldier);

    //returns an ostreaqm object containing a short description about the instance
    std::ostream& toString(std::ostream& out);


    //returns the type (name) of the class ShieldArmor
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_SHEILDARMOR_H
