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

    //ctor. receives the player's army identifier and the Player's name
    Player(const int army, const std::string &name);

    //Adds a Soldier instance to the Soldiers vector
    void addSoldier(Soldier* soldier);

    //Pure virtual method. Invoked when it is the turn of the Player.
    virtual void playTurn(Game* game) = 0;

    //Returns an ostream instance containing a short description of the Player
    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    //dtor
    virtual ~Player() = 0;

    //Returns true if there is at least one soldier who
    //hasn't done reaching it's all destinaions.
    //Returns false otherwise
    virtual bool isPlaying();
};

#endif //EX2_CPP_SEFI_PLAYER_H
