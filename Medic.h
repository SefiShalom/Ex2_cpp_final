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
    Medic(const Point& position, const short army);
    virtual ~Medic();
    void heal(Soldier* injured);
    virtual bool attack(Soldier *target);
    void healMe();
    void whoAreYou();
    void walk();
    void performAction(Soldier* soldier);
    void performAction(Weapon* weapon);
    virtual std::vector<MapObject*> kill();
    std::ostream& toString (std::ostream& out);

};


#endif //EX2_CPP_SEFI_MEDIC_H
