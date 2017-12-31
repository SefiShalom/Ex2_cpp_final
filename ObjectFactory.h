//
// Created by damir on 30-Dec-17.
//

#ifndef EX2_CPP_SEFI_WEAPONFACTORY_H
#define EX2_CPP_SEFI_WEAPONFACTORY_H


#include <vector>
#include "Weapon.h"
#include "SolidObject.h"
#include "Armor.h"

class ObjectFactory {

public:

    static Weapon* makeWeapon(const std::vector<std::string> &info);

    static Armor* makeArmor(const std::vector<std::string> &info);

    static SolidObject* makeSolidObject(const std::vector<std::string> &info);

};


#endif //EX2_CPP_SEFI_WEAPONFACTORY_H
