//
// Created by Sefi on 16/12/2017.
//

#include "Armor.h"

Armor::Armor(Point* position, double defensePower)
        :CollectableObject(position),_defensePower(defensePower){}

Armor::~Armor(){};

double Armor::getDefensePower(){
return _defensePower;
}
