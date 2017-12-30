//
// Created by damir on 26-Dec-17.
//

#include "Game.h"
#include "GameFileParser.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "SoldierFactory.h"
#include "ObjectFactory.h"

Game::Game()
        : _battlefield(nullptr) {}

Game::~Game() {
    std::vector<MapObject *>::iterator it;
    for (it = _gameMap.begin(); it != _gameMap.end(); it++) delete *it;
    delete _battlefield;      // CAUSES SEGMENTATION FAULT FOR SOME REASON!
    for (auto &p : _players) {
        delete (p);
    }
}

std::vector<MapObject *> Game::retrieveObjectsInRadius(Soldier *soldier, double radius) {
    std::vector<MapObject *> objectInRadius;
    std::vector<MapObject *>::iterator it;
    for (it = _gameMap.begin(); it != _gameMap.end(); it++) {
        if (*it != soldier && (*it)->getLocation().distance(soldier->getLocation()) <= radius)
            objectInRadius.emplace_back(*it);
    }
    return objectInRadius;
}


std::vector<MapObject *> Game::retrieveObjectsWithinRadiusByPoint(const Point& point, double radius) {
    std::vector<MapObject *> objectInRadius;
    std::vector<MapObject *>::iterator it;
    for (it = _gameMap.begin(); it != _gameMap.end(); it++) {
        if ((*it)->getLocation().distance(point) <= radius)
            objectInRadius.emplace_back(*it);
    }
    return objectInRadius;
}


MapObject *Game::getClosestObject(const Point& point, double radius) {
    double minDistance = Point(0,0).distance(Point(_battlefield->getWidth(), _battlefield->getHeight())); // Max distance
    MapObject *ret = nullptr;
//    std::cout << "Point to look for is " << point << "\n" << std::endl;
    for (auto &it : _gameMap) {

//        std::cout << "Checking mapObj at point " << it->getLocation() << std::endl;

        double possibleMin = point.distance(it->getLocation());
        if (possibleMin < minDistance) {
            minDistance = possibleMin;
            if (minDistance <= radius) {
                ret = it;
            }
        }
    }

    return ret;
}


void Game::addMapObject(MapObject *object) {
    _gameMap.emplace_back(object);
}

std::vector<MapObject *> &Game::getAllObjects() {
    return _gameMap;
}

void Game::initGame(const std::string &path) {

    GameFileParser gfp(path);
    if (!gfp.isGood()) {
        return;
    }
    std::vector<std::vector<std::string>> csv = gfp.parse();

    _battlefield = new Battlefield(std::stoi(csv[BATTLEFIELD_LINE][1]), std::stoi(csv[BATTLEFIELD_LINE][2]));
    int numOfPlayers = std::stoi(csv[PLAYERS_LINE][1]);
    int numOfSoldiersPerPlayer = std::stoi(csv[NUM_OF_SOLDIERS_LINE][1]);

    int startSearchingObjectsFrom = 4 + (numOfPlayers * (numOfSoldiersPerPlayer + 1));

    if (!addAllMapObject(startSearchingObjectsFrom, csv)) {
        std::cout << "Error parsing objects!" << std::endl;
    }

    for (int i = 0; i < numOfPlayers; ++i) {
        int startReadingPlayerInfoFrom = 5 + (numOfSoldiersPerPlayer + 1) * i;

        bool isComputer = csv[4 + (numOfSoldiersPerPlayer + 1) * i][1] == "computer";

        Player *p_i = generatePlayerWithSoldiers(i, startReadingPlayerInfoFrom, numOfSoldiersPerPlayer, csv,
                                                 isComputer);

        if (p_i == nullptr) {
            std::cout << "Error creating player!" << std::endl;
        }

        std::cout << "Created a player: " << *p_i << std::endl;

        _players.emplace_back(p_i);
    }

}

Player *
Game::generatePlayerWithSoldiers(int playerNumber, int startReadingFrom, int numOfSoldiers,
                                 const std::vector<std::vector<std::string>> &csv, bool isComputer) {

    std::string pc = "Computer";
    std::string human = "Human";

    Player *player;
    if (isComputer) {
        player = new ComputerPlayer(playerNumber, pc + std::to_string(playerNumber));
    } else {
        player = new HumanPlayer(playerNumber, human + std::to_string(playerNumber));
    }

    int ind = 0;

    for (int i = 0; i < numOfSoldiers; ++i) {
        Soldier *newSoldier = SoldierFactory::makeSoldier(csv[startReadingFrom], playerNumber);
        if (newSoldier == nullptr) {
            std::cout << "Error creating a soldier for player number " << playerNumber << std::endl;
            return nullptr;
        }
        player->addSoldier(newSoldier);
        ++startReadingFrom;
    }

    return player;


}

void Game::killSoldier(Soldier *soldier) {

    std::vector<MapObject *> objects = soldier->kill();

    auto i = objects.begin();
    auto j = _gameMap.begin();

    while (i != objects.end())
        while (j != _gameMap.end())
            if (*i != *j) {
                delete *i;
                _gameMap.erase(j);
            }
}


bool Game::addAllMapObject(int from, const std::vector<std::vector<std::string>> &csv) {

    if (csv[from][0] != "Objects")
        return false;

    for (int i = from + 1; i < csv.size(); ++i) {
        if (csv[i][0] == "weapon") {
            Weapon *weapon = ObjectFactory::makeWeapon(csv[i]);
            addMapObject(weapon);

        } else if (csv[i][0] == "Armor") {
            Armor *armor = ObjectFactory::makeArmor(csv[i]);
            addMapObject(armor);
        } else if (csv[i][0] == "solid") {
            SolidObject *solidObject = ObjectFactory::makeSolidObject(csv[i]);
            addMapObject(solidObject);
        } else {
            return false;
        }
    }

    return true;
}


void Game::attack(Soldier *attacker, Soldier *target) {
    if (attacker->attack(target)) killSoldier(target);

}

Battlefield Game::getBattlefield() {
    return *_battlefield;
}



