//
// Created by Sefi on 31/12/2017.
//

#ifndef EX2_CPP_SEFI_SNIPERSTRATEGY_H
#define EX2_CPP_SEFI_SNIPERSTRATEGY_H


#include "MapObject.h"
#include "Game.h"

class SniperStrategy: public SoldierStrategy {

    //dtor
    ~SniperStrategy();

    //receives a Soldier and the Game instances and applies the strategy in the soldier
    //based on the game current state
    virtual std::vector<MapObject*> applyStrategy(Soldier* soldier, Game* game);
};


#endif //EX2_CPP_SEFI_SNIPERSTRATEGY_H
