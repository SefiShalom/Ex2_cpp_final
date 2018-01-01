//
// Created by damir on 17-Dec-17.
//

#include "Player.h"

#include "Player.h"
#include "SniperStrategy.h"
#include "RegularSoldierStrategy.h"
#include "MedicStrategy.h"

int Player::_armyCounter = 0;


Player::Player(const int army, const std::string &name)
        : _army(army), _name(name), sniperStrat(new SniperStrategy), medicStrat(new MedicStrategy), regularStrat(new RegularSoldierStrategy) {}


std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player: " << player._name << std::endl;
    os << "Army: " << player._army << std::endl;
    os << "Soldiers: " << std::endl;
    int i = 1;
    for (auto& soldier : player._soldiers) {
        std::cout << i << ") " << *soldier << std::endl;
        ++i;
    }
    return os;
}

void Player::addSoldier(Soldier *soldier) {
    _soldiers.emplace_back(soldier);
}

Player::~Player() {
    for (auto &it : _soldiers) {
//        delete it;
    }
    delete sniperStrat;
    delete medicStrat;
    delete regularStrat;
}

bool Player::isPlaying() {

    for (auto &it : _soldiers) {
        if (it->isWalking()) {
            return true;
        }
    }

    return false;
}



