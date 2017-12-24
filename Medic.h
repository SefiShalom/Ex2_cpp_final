//
// Created by damir on 16-Dec-17.
//

#ifndef EX2_CPP_SEFI_MEDIC_H
#define EX2_CPP_SEFI_MEDIC_H


#include "Soldier.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "Fists.h"

#define MEDIC_HP 120
#define MEDIC_SPEED 4

class Medic : public Soldier {

    Fists* fists;

public:
    Medic(Point* currPosition, const short army);
    virtual ~Medic();
    void heal(Soldier* injured);
    virtual void attack(Soldier *target);
    void pickObject(Weapon* weapon);
    void pickObject(BodyArmor* weapon);
    void pickObject(ShieldArmor* weapon);
    void healMe();
    void whoAreYou();
};


#endif //EX2_CPP_SEFI_MEDIC_H
