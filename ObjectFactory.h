//
// Created by damir on 30-Dec-17.
//

#ifndef EX2_CPP_SEFI_WEAPONFACTORY_H
#define EX2_CPP_SEFI_WEAPONFACTORY_H


#include <vector>
#include "Weapon.h"
#include "SolidObject.h"
#include "Armor.h"


/**
 *  This class generates weapons, armors and solid objects from a given vector of strings
 */
class ObjectFactory {

public:

    //  Generates a weapon
    static Weapon* makeWeapon(const std::vector<std::string> &info);

    //  Generates an armor
    static Armor* makeArmor(const std::vector<std::string> &info);

    //  Generates a solid object
    static SolidObject* makeSolidObject(const std::vector<std::string> &info);

};


#endif //EX2_CPP_SEFI_WEAPONFACTORY_H
