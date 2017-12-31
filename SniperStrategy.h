//
// Created by Sefi on 31/12/2017.
//

#ifndef EX2_CPP_SEFI_SNIPERSTRATEGY_H
#define EX2_CPP_SEFI_SNIPERSTRATEGY_H


#include "MapObject.h"
#include "Game.h"

class SniperStrategy: public SoldierStrategy {
    virtual MapObject* applyStrategy(Soldier* soldier, Game* game);
};


#endif //EX2_CPP_SEFI_SNIPERSTRATEGY_H
