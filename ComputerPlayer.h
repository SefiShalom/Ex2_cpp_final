//
// Created by damir on 29-Dec-17.
//

#ifndef EX2_CPP_SEFI_COMPUTERPLAYER_H
#define EX2_CPP_SEFI_COMPUTERPLAYER_H


#include "Player.h"
#include "ComputerStrategy.h"
#include "Battlefield.h"

class ComputerPlayer : public Player {

    ComputerStrategy* comStrat;
    int _strategy;
    Battlefield *_battlefield;
public:
    ComputerPlayer(const int army, const std::string &name, int strat, Battlefield battlefield);

    virtual void playTurn(Game* game);

    virtual bool isPlaying();
};


#endif //EX2_CPP_SEFI_COMPUTERPLAYER_H
