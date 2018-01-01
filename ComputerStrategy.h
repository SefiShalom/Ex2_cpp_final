//
// Created by damir on 01-Jan-18.
//

#ifndef EX2_CPP_SEFI_COMPUTERSTRATEGY_H
#define EX2_CPP_SEFI_COMPUTERSTRATEGY_H


#include <vector>
#include "Point.h"
#include "Battlefield.h"

class ComputerStrategy {

    Point randomizedStrategy(Battlefield *battlefield);

    Point defaultStrategy();

public:

    Point applyStrategy(int strat, Battlefield *battlefield);
};


#endif //EX2_CPP_SEFI_COMPUTERSTRATEGY_H
