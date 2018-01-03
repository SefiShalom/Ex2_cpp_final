//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_MEDICSTRATEGY_H
#define EX2_CPP_SEFI_MEDICSTRATEGY_H


#include "SoldierStrategy.h"

class MedicStrategy : public SoldierStrategy{

public:

    //dotr
    ~MedicStrategy();

    //receives a Soldier and the Game instances and applies the strategy in the soldier
    //based on the game current state
    std::vector<MapObject*> applyStrategy(Soldier* soldier, Game* game);

};


#endif //EX2_CPP_SEFI_MEDICSTRATEGY_H
