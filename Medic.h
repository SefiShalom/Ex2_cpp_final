//
// Created by damir on 16-Dec-17.
//

#ifndef EX2_CPP_SEFI_MEDIC_H
#define EX2_CPP_SEFI_MEDIC_H


#include "Soldier.h"
#include "Fists.h"

class Medic : public Soldier {

    Fists* fists;

public:
    Medic(const Point &currPosition, size_t hp, double speed, const int army);

    void heal(Soldier* injured);

    virtual void attack(Soldier *target);

    virtual void pickObject(CollectableObject *object);

    virtual void dropObject(Point position);

    virtual void defend(Weapon* attack);

    virtual const Point getCurrentPosition();

    void whoAreYou();

};


#endif //EX2_CPP_SEFI_MEDIC_H
