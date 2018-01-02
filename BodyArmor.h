//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_BODYARMOR_H
#define EX2_CPP_SEFI_BODYARMOR_H


#include "Armor.h"
#include "Weapon.h"
#include "Soldier.h"

class BodyArmor : public Armor {

    //A derived class of Armor
    //Represents a BodyArmor that a soldier wears upon it's body

public:
    BodyArmor(const Point& position, double defensePower);//ctor. gets the initial position and the defense power

    ~BodyArmor();//dtor

    void drop(Soldier* soldier);//drops the BodyArmor in the given soldier's current position

    double defend(Weapon *weapon);// reduces the given Weapon attack power by the BodyArmor defense power

    void useObject(Soldier* soldier);// invokes the given soldier 'pickObject' method which assigning the BodyArmor to it.

    void acceptAction(Soldier* soldier);// passing the instance to the given Soldier's 'performAction'
                                        // to perform the relevant action on the instance

    std::ostream& toString(std::ostream& out);//returns an ostreaqm object containing a short description if the BodyArmor

    virtual std::string getType();//returns the type (name) of the class BodyArmor
};


#endif //EX2_CPP_SEFI_BODYARMOR_H
