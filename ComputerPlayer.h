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
    ComputerPlayer(const int army, const std::string &name, int strat, Battlefield *battlefield);//ctor. receives the army num
                                                                                                // the player's name, strategy identifier
                                                                                                // and a pointer to the battlefield
    ~ComputerPlayer();//dtor

    virtual void playTurn(Game* game);//invikes each soldier 'walk' function and let each take relevant actions

    virtual bool isPlaying();//checks if there is at least one soldier alive. returns false otherwise
};


#endif //EX2_CPP_SEFI_COMPUTERPLAYER_H
