//
// Created by damir on 17-Dec-17.
//

#include "Player.h"

#include "Player.h"

int Player::_armyCounter = 0;


Player::Player(std::string name)
        : _army(_armyCounter++), _name(name) {}


std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Printing player " << player._name << std::endl;
    os << "Army: " << player._army << std::endl;
    for (auto& soldier : player._soldiers) {
        std::cout << soldier << std::endl;
    }
}



