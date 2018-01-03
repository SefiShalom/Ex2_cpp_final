//
// Created by damir on 19-Dec-17.
//

#ifndef EX2_CPP_SEFI_FISTS_H
#define EX2_CPP_SEFI_FISTS_H

#include <memory>
#include "Weapon.h"

#define FISTS_POWER 10
#define FISTS_BULLETS_PER_SHOT 1


class Fists : public Weapon {
//A derived class of Weapon
public:
    Fists();// ctor. does not receive any arguments
    ~Fists();//dtor

    //An implementation of the Visitor design pattern. Represent the visit(Visited*) method.
    double attackArmor(ShieldArmor* sheild);
    double attackArmor(BodyArmor* armor);

    //Implemented for the Visitor design pattern implementation
    void useObject(Soldier* soldier);

    //Implemented for the Visitor design pattern implementation
    //Deletes the Fists instance of the given soldier
    void drop(Fighter* figter);

    //Returns an ostream containing a basic information about the instance
    std::ostream& toString(std::ostream& out);

    //Returns false - Fists is not a fire arm
    virtual bool isFireArm();

    //Returns the identifier (name) of Fists class
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_FISTS_H
