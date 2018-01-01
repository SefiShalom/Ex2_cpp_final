//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_MEDICSTRATEGY_H
#define EX2_CPP_SEFI_MEDICSTRATEGY_H


#include "SoldierStrategy.h"

class MedicStrategy : public SoldierStrategy{

public:
    ~MedicStrategy();
    std::vector<MapObject*> applyStrategy(Soldier* soldier, Game* game);

};


#endif //EX2_CPP_SEFI_MEDICSTRATEGY_H
