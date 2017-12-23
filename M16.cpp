//
// Created by Sefi on 20/12/2017.
//

#include "M16.h"


M16::M16(Point* position)
        :Rifle(position,M16_POWER,M16_BULLETSPERSHOT){}

M16::~M16(){}

void M16::useObject(Soldier *soldier) {
    soldier->pickObject(this);
}
