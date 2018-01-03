//
// Created by damir on 01-Jan-18.
//

#ifndef EX2_CPP_SEFI_COMPUTERSTRATEGY_H
#define EX2_CPP_SEFI_COMPUTERSTRATEGY_H


#include <vector>
#include "Point.h"
#include "Battlefield.h"


/**
 *  This class determines the computer strategy by given strategy number
 */
class ComputerStrategy {

    //  A certain randomized strategy. Gives the soldier a randomized point to go to
    Point randomizedStrategy(Battlefield *battlefield);

    //  Default strategy --> Every soldier will go to the point [0 0]
    Point defaultStrategy();

public:

    //  Returns a point by the strategy number given
    Point applyStrategy(int strat, Battlefield *battlefield);
};


#endif //EX2_CPP_SEFI_COMPUTERSTRATEGY_H
