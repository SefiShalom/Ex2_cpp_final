//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_HUMANPLAYER_H
#define EX2_CPP_SEFI_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:

    HumanPlayer(const int army, const std::string &name);

    virtual void playTurn();

    void initSteps(std::vector<std::vector<Point *>> points);
};


#endif //EX2_CPP_SEFI_HUMANPLAYER_H
