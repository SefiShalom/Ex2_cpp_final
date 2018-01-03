//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_HUMANPLAYER_H
#define EX2_CPP_SEFI_HUMANPLAYER_H


#include "Player.h"


class HumanPlayer : public Player {

    //A derived class of Player.
    //Represent a human player


public:

    //ctor. receives the HumanPlayer's army identifier and the Player's name
    HumanPlayer(const int army, const std::string &name);

    //dtor
    virtual ~HumanPlayer();

    //Invoked when it is the turn of the Player. Moves the soldiers on the battlefield and
    //let them perform action on the other MapObjects instances ariund them
    virtual void playTurn(Game* game);

    //Feeds each soldier with it's destinations in the game
    //invoked before the game begins
    void initSteps(std::vector<std::vector<Point>> points);

};


#endif //EX2_CPP_SEFI_HUMANPLAYER_H
