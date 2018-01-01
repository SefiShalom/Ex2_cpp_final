//
// Created by damir on 29-Dec-17.
//

#include "ComputerPlayer.h"
#include "Medic.h"
#include "SniperSoldier.h"
#include "Game.h"

ComputerPlayer::ComputerPlayer(const int army, const std::string &name, int strat, Battlefield battlefield)
        : Player(army, name), _strategy(strat), _battlefield(&battlefield) {
}

void ComputerPlayer::playTurn(Game *game) {

    for (auto &soldier : _soldiers) {

        if (soldier->isAlive()) {

            if (!soldier->isWalking()) {
                soldier->setNextDestination(comStrat->applyStrategy(_strategy, *_battlefield));
            }

            std::cout << "It's " << *soldier << "'s turn" << std::endl;
            soldier->walk();
            if (dynamic_cast<Medic *>(soldier)) {
                game->applyStrategy(soldier, medicStrat);
            } else if (dynamic_cast<SniperSoldier *>(soldier)) {
                game->applyStrategy(soldier, sniperStrat);
            } else {  // Regular soldier
                game->applyStrategy(soldier, regularStrat);
            }

        }

    }

}

bool ComputerPlayer::isPlaying() {

    for (auto &it : _soldiers) {
        if (it->isAlive()){
            return true;
        }
    }
    return false;
}
