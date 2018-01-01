//
// Created by damir on 01-Jan-18.
//

#include "ComputerStrategy.h"

Point ComputerStrategy::applyStrategy(int strat, Battlefield battlefield) {
    switch (strat) {
        case 0:
            return randomizedStrategy(battlefield);

        default:
            std::cerr << "No such strategy. Applied default strategy." << std::endl;
            return defaultStrategy();
    }
}

Point ComputerStrategy::randomizedStrategy(Battlefield battlefield) {

    double maxY = battlefield.getHeight();
    double maxX = battlefield.getWidth();

    double randX = rand() % (((int) maxX + 1));
    double randY = rand() % (((int) maxY + 1));

    Point ret(randX, randY);

    return ret;
}

Point ComputerStrategy::defaultStrategy() {
    return Point();
}
