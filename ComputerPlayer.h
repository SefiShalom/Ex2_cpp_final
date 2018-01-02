//
// Created by damir on 29-Dec-17.
//

#ifndef EX2_CPP_SEFI_COMPUTERPLAYER_H
#define EX2_CPP_SEFI_COMPUTERPLAYER_H


#include "Player.h"
#include "ComputerStrategy.h"
#include "Battlefield.h"

class ComputerPlayer : public Player {
    //A dervied class of Player class
    ComputerStrategy* comStrat;// a pointer to a ComputerStrategy objects
    int _strategy;// the identifier number of the strategy
    Battlefield *_battlefield;// a pointer to the Game's Battlefield instance
public:
    ComputerPlayer(const int army, const std::string &name, int strat, Battlefield *battlefield);//ctor

    virtual void playTurn(Game* game);

    virtual bool isPlaying();
};


#endif //EX2_CPP_SEFI_COMPUTERPLAYER_H
