//
// Created by Sefi on 31/12/2017.
//

#ifndef EX2_CPP_SEFI_REGULARSOLDIERSTRATEGY_H
#define EX2_CPP_SEFI_REGULARSOLDIERSTRATEGY_H


#include "SoldierStrategy.h"


class RegularSoldierStrategy: public SoldierStrategy{

public:
    ~RegularSoldierStrategy();
    std::vector<MapObject*> applyStrategy(Soldier* soldier, Game* game);


};


#endif //EX2_CPP_SEFI_REGULARSOLDIERSTRATEGY_H
