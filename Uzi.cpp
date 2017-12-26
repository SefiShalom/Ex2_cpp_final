//
// Created by Sefi on 26/12/2017.
//

#include "Uzi.h"

Uzi::Uzi(const Point &position)
        :Rifle(position,UZI_POWER,UZI_BULLETS_PER_SHOT){}

Uzi::~Uzi() {}

void Uzi::useObject(Fighter *fighter) {
    fighter->pickObject(this);
}

void Uzi::useObject(std::shared_ptr<Fighter> fighter) {
    fighter->pickObject(this);
}
