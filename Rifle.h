//
// Created by Sefi on 12/12/2017.
//

#ifndef EX2_CPP_SEFI_RIFLE_H
#define EX2_CPP_SEFI_RIFLE_H

#include <memory>

#include "Weapon.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"

class Rifle: public Weapon {

 public:
    Rifle(const Point& position,size_t power,size_t bulletsPerShot);
    virtual ~Rifle() = 0;
    double attackArmor(ShieldArmor* sheild);
    double attackArmor(BodyArmor* bodyarmor);
    void drop(Fighter* figter);

    double attackArmor(std::shared_ptr<ShieldArmor> shield);

    double attackArmor(std::shared_ptr<BodyArmor> bodyarmor);

    void drop(std::shared_ptr<Fighter> fighter);
};


#endif //EX2_CPP_SEFI_RIFLE_H
