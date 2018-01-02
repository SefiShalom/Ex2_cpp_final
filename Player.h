//
// Created by damir on 17-Dec-17.
//

#ifndef EX2_CPP_SEFI_PLAYER_H
#define EX2_CPP_SEFI_PLAYER_H

#include <vector>
#include "Soldier.h"

class Game;

class Player {

    friend class Game;
    friend class Output;

protected:
    std::vector<Soldier *> _soldiers;
    static int _armyCounter;
    const int _army;
    const std::string _name;

    SoldierStrategy *sniperStrat;
    SoldierStrategy *medicStrat;
    SoldierStrategy *regularStrat;

public:

    Player(const int army, const std::string &name);

    void addSoldier(Soldier* soldier);

    virtual void playTurn(Game* game) = 0;

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    virtual ~Player() = 0;

    virtual bool isPlaying();
};


#endif //EX2_CPP_SEFI_PLAYER_H
