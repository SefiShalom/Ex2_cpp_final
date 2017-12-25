//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_BODYARMOR_H
#define EX2_CPP_SEFI_BODYARMOR_H

#include <memory>

#include "Armor.h"
#include "Weapon.h"
#include "Soldier.h"

class BodyArmor : public Armor {

public:
    BodyArmor(const Point& position, double defensePower);

    ~BodyArmor();
    void drop(Soldier* soldier);
    double defend(Weapon *weapon);
    void useObject(Soldier* soldier);

    virtual double defend(std::shared_ptr<Weapon> weapon);
    virtual void drop(std::shared_ptr<Soldier> soldier);
    virtual void useObject(std::shared_ptr<Soldier> soldier);
};


#endif //EX2_CPP_SEFI_BODYARMOR_H
