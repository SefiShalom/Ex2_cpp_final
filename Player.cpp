//
// Created by damir on 17-Dec-17.
//

#include "Player.h"


int Player::_armyCounter = 0;


Player::Player(std::string name)
        : _army(_armyCounter++), _name(name) {}

void Player::initSteps(std::vector<std::vector<Point>> points) {
    size_t index = 0;
    for (auto& soldier : _soldiers) {
        soldier->feedMeWithDestinations(points[index]);
        index++;
    }
}


std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Printing player " << player._name << std::endl;
    os << "Army: " << player._army << std::endl;
    for (auto& soldier : player._soldiers) {
        std::cout << soldier << std::endl;
    }
}



