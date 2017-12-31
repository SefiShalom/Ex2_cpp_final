//
// Created by damir on 26-Dec-17.
//

#include "HumanPlayer.h"
#include "Game.h"

HumanPlayer::HumanPlayer(const int army, const std::string &name) : Player(army, name) {}

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
        while (soldier->isWalking()) {
            soldier->walk();
            std::vector<MapObject *> objects = game->retrieveObjectsInRadius(soldier, 2);
            for (auto &object: objects) {
                std::cout << *object << std::endl;
                object->acceptAction(soldier);
            }
        }
    }
}
