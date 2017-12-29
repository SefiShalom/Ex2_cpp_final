//
// Created by damir on 29-Dec-17.
//

#ifndef EX2_CPP_SEFI_COMPUTERPLAYER_H
#define EX2_CPP_SEFI_COMPUTERPLAYER_H


#include "Player.h"

class ComputerPlayer : public Player {

public:
    ComputerPlayer(const int army, const std::string &name);

    virtual void playTurn();
};


#endif //EX2_CPP_SEFI_COMPUTERPLAYER_H
