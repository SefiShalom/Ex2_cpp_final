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

    Fighter(const Point& position, size_t hp, double speed, const int army);
    virtual ~Fighter();
    virtual void attack(Soldier *target);
    void pickObject(BodyArmor* ba);
    void pickObject(ShieldArmor* sa);
    virtual void pickObject(Weapon* weapon);
    void set_weapon(Weapon* weapon);
    virtual double calculateHitChance(Soldier* enemy) const = 0;
//    void defend(Weapon* weapon);
};


#endif //EX2_CPP_SEFI_FIGHTER_H
