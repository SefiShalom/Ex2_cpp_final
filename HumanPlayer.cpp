//
// Created by damir on 26-Dec-17.
//

#include "HumanPlayer.h"
#include "Game.h"
#include "Medic.h"
#include "SniperSoldier.h"

HumanPlayer::HumanPlayer(const int army, const std::string &name)
        : Player(army, name) {}

void HumanPlayer::initSteps(std::vector<std::vector<Point>> points) {
    size_t index = 0;
    for (auto &soldier : _soldiers) {
//        soldier->setNextDestination(Point(20, 20));
        soldier->feedMeWithDestinations(points[index]);
        index++;
    }
}

void HumanPlayer::playTurn(Game *game) {
    for (auto &soldier : _soldiers) {
        if (soldier->isAlive()) {
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

HumanPlayer::~HumanPlayer() {

}


