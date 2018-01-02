//
// Created by Sefi on 16/12/2017.
//

#ifndef EX2_CPP_SEFI_ARMOR_H
#define EX2_CPP_SEFI_ARMOR_H

#include <memory>
#include "CollectableObject.h"

class Weapon;

//abstract class Armor
class Armor: public CollectableObject{

    double _defensePower;//an Armor's defense power. a number between 0.65 (best defense) - 1.0 (no defense)

public:
    Armor(const Point& position, double defensePower);//ctor
    virtual ~Armor()=0;//dtor
    virtual double defend(Weapon* weapon)=0;//abstract method. implemented differently in each derived class
    virtual void drop(Soldier* soldier) = 0;//abstract method. implemented differently in each derived class
    double getDefensePower();// returns the defense power of the Armor
};

#endif //EX2_CPP_SEFI_ARMOR_H
