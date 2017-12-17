//
// Created by damir on 17-Dec-17.
//

#ifndef EX2_CPP_SEFI_PLAYER_H
#define EX2_CPP_SEFI_PLAYER_H

#include <vector>
#include "Soldier.h"

class Player {

    std::vector<Soldier*> _soldiers;
    static int _army;

public:

    void initSteps();

};


#endif //EX2_CPP_SEFI_PLAYER_H
