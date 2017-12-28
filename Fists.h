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

public:
    Fists();
    ~Fists();
    double attackArmor(ShieldArmor* sheild);
    double attackArmor(BodyArmor* armor);
    void useObject(Soldier* soldier);
    void drop(Fighter* figter);
    std::ostream& toString(std::ostream& out);

};


#endif //EX2_CPP_SEFI_FISTS_H
