//
// Created by damir on 19-Dec-17.
//

#ifndef EX2_CPP_SEFI_FISTS_H
#define EX2_CPP_SEFI_FISTS_H

#include <memory>
#include "Weapon.h"

#define FISTS_POWER 10
#define BULLETS_PER_SHOT 1


class Fists : public Weapon {

public:
    Fists();
    ~Fists();
    double attackArmor(ShieldArmor* sheild);
    double attackArmor(BodyArmor* armor);
    void useObject(Soldier* soldier);
    void drop(Fighter* figter);

    double attackArmor(std::shared_ptr<ShieldArmor> shield);

    double attackArmor(std::shared_ptr<BodyArmor> bodyarmor);

    void useObject(std::shared_ptr<Soldier> soldier);

    void drop(std::shared_ptr<Fighter> fighter);
};


#endif //EX2_CPP_SEFI_FISTS_H
