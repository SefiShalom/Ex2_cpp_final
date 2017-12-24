//
// Created by damir on 19-Dec-17.
//

#ifndef EX2_CPP_SEFI_FIGHTER_H
#define EX2_CPP_SEFI_FIGHTER_H


#include "Soldier.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "Fists.h"

class Fighter : public Soldier {

    Weapon* _weapon;

public:

    Fighter(Point* currPosition, size_t hp, double speed, const int army);
    virtual ~Fighter();
    virtual void attack(Soldier *target);
    void pickObject(BodyArmor* ba);
    void pickObject(ShieldArmor* sa);
    void pickObject(Weapon* weapon);
    void set_weapon(Weapon* weapon);
};


#endif //EX2_CPP_SEFI_FIGHTER_H
