//
// Created by damir on 17-Dec-17.
//

#ifndef EX2_CPP_SEFI_PLAYER_H
#define EX2_CPP_SEFI_PLAYER_H

#include <vector>
#include "Soldier.h"

class Player {

    friend class Game;

    std::vector<Soldier*> _soldiers;
    static int _armyCounter;
    const int _army;
    const std::string _name;

public:

    explicit Player(std::string name);
    void initSteps(std::vector<std::vector<Point>> points);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};




#endif //EX2_CPP_SEFI_PLAYER_H