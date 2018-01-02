//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_SOLDIERSTRATEGY_H
#define EX2_CPP_SEFI_SOLDIERSTRATEGY_H


#include <vector>
#include "MapObject.h"

class Game;

//  Interface for various soldier types

class SoldierStrategy {

public:

    virtual ~SoldierStrategy() = 0;

    virtual std::vector<MapObject *> applyStrategy(Soldier *soldier, Game *game) = 0;

};


#endif //EX2_CPP_SEFI_SOLDIERSTRATEGY_H
