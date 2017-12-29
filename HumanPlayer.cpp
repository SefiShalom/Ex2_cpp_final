//
// Created by damir on 26-Dec-17.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const int army, const std::string &name) : Player(army, name) {}

void HumanPlayer::initSteps(std::vector<std::vector<Point*>> points) {
    size_t index = 0;
    for (auto& soldier : _soldiers) {
        soldier->feedMeWithDestinations(points[index]);
        index++;
    }
}

void HumanPlayer::playTurn() {

    // TODO

}
