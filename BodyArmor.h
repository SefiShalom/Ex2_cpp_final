//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_BODYARMOR_H
#define EX2_CPP_SEFI_BODYARMOR_H

#include <memory>

#include "Armor.h"
#include "Weapon.h"
#include "Soldier.h"

class BodyArmor : public Armor, public std::enable_shared_from_this<BodyArmor> {

public:
    BodyArmor(const Point& position, double defensePower);

    ~BodyArmor();
    void drop(Soldier* soldier);
    double defend(Weapon *weapon);
    void useObject(Soldier* soldier);
    void acceptAction(Soldier* soldier);
    std::ostream& toString(std::ostream& out);
    virtual std::string getType();
};


#endif //EX2_CPP_SEFI_BODYARMOR_H
