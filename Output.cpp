//
// Created by damir on 02-Jan-18.
//

#include <sstream>
#include "Output.h"

int Output::iteration = 1;

Output::Output() {

    _output.open("output.csv", std::ofstream::out);

    _isValid = _output.is_open();

}

void Output::write(Game *game) {

    _output << "Iteration number " << iteration++ << std::endl;

    for (auto &player : game->getAllPlayers()) {

        _output << player->_name << ",Army: " << player->_army << std::endl;

        for (auto &soldier : player->_soldiers) {
            bool _hasBodyArmor = (soldier->get_bodyarmor() != nullptr);
            bool _hasShield = (soldier->get_shield() != nullptr);
            std::stringstream pointOrDead;
            if (soldier->getLocation().get_x() == -INFINITY) {
                pointOrDead << "DEAD";
            } else {
                pointOrDead << soldier->getLocation();
            }

            _output << soldier->getType() << ",ID:" << soldier->getID() << ",HP:" << soldier->getHP()
                    << "," << pointOrDead.str() << "," << soldier->get_weapon()->getType();

            if (_hasBodyArmor) {
                _output << "," << soldier->get_bodyarmor()->getType() << "," << soldier->get_bodyarmor()->getDefensePower();
            }
            if (_hasShield) {
                _output << "," << soldier->get_shield()->getType() << "," << soldier->get_shield()->getDefensePower();
            }
            _output << std::endl;
        }
    }

    _output << "\nObjects:" << std::endl;

    for (auto &obj : game->getAllObjects()) {

        if (obj->getType() != "Regular" && obj->getType() != "Sniper" && obj->getType() != "Medic" && obj->getLocation().get_x() != -INFINITY) {
            _output << obj->getType() << "," << obj->getLocation();
            if (obj->getType() == "BodyArmor" || obj->getType() == "ShieldArmor") {
                _output << "," << ((Armor*)obj)->getDefensePower();
            }
            _output << std::endl;
        }

    }
    _output << std::endl;

}

Output::~Output() {
    _output.close();
}

bool Output::isValid() {
    return _isValid;
}

void Output::endGame(Game *game) {
    for (auto &player : game->getAllPlayers()) {
        _output << player->_name << ",Army: " << player->_army;
        if (!player->isPlaying()) {
            _output << ",LOST" << std::endl;
        } else {
            _output << ",WON" << std::endl;
        }
    }
}
