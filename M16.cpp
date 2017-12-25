//
// Created by Sefi on 20/12/2017.
//

#include "M16.h"


M16::M16(const Point& position)
        :Rifle(position,M16_POWER,M16_BULLETSPERSHOT){}

M16::~M16(){}

void M16::useObject(Fighter *soldier) {
    soldier->pickObject(this);
}

void M16::useObject(std::shared_ptr<Fighter> fighter) {
    fighter->pickObject(std::make_shared<M16>(*this));
}
