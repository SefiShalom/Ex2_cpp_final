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
#include "FileReader.h"
#include "FileTokenizer.h"
#include "PointsFactory.h"

Game::Game()
        : _battlefield(nullptr) {}

Game::~Game() {
    std::vector<MapObject *>::iterator it;
    for (it = _gameMap.begin(); it != _gameMap.end(); it++)
        delete *it;
    delete _battlefield;      // CAUSES SEGMENTATION FAULT FOR SOME REASON!
    for (auto &p : _players) {
        delete (p);
    }
}

std::vector<CollectableObject *> Game::retrieveCollectablesInRadius(Soldier *soldier) {
    std::vector<CollectableObject *> objectInRadius;
    for (auto & it : _gameMap) {
        if (dynamic_cast<CollectableObject*>(it) && (it)->getLocation().distance(soldier->getLocation()) <= PICKABLE_RADIUS){
            objectInRadius.emplace_back(dynamic_cast<CollectableObject*>(it));
        }
    }
    return objectInRadius;
}

std::vector<Soldier *> Game::retrieveEnemySoldiers(Soldier *soldier) {
    std::vector<Soldier *> enemySoldiers;
    for (auto & it : _gameMap) {
        if (Soldier* t = dynamic_cast<Soldier*>(it)) {
            if(t->getArmy() != soldier->getArmy() && t->isAlive()){
                enemySoldiers.emplace_back(t);
            }

        }
    }
    return enemySoldiers;
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

    for (int i = 0; i < numOfPlayers; ++i) {
        std::vector<Soldier*> vec = _players[i]->_soldiers;

        for (auto &it : vec) {
            addMapObject(it);

            if(it->get_weapon()/* && it->get_weapon()->isFireArm()*/){
                std::cout << "Added " << *it->get_weapon() << std::endl;
                addMapObject(it->get_weapon());
            }
            if(it->get_shield()) addMapObject(it->get_shield());
            if(it->get_bodyarmor()) addMapObject(it->get_bodyarmor());

        }

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
//        addMapObject(newSoldier);
        ++startReadingFrom;
    }

    if(!isComputer){

        FileReader fr("csvs/player" + std::to_string(playerNumber) + "_file.csv");
        std::string file = fr.getText();
        FileTokenizer ft(file);
        std::vector<std::string> pointStr = ft.tokenizeBy("\n");

        int index = 1;
        for (auto &sol : player->_soldiers) {
            if (index >= pointStr.size()) {
                std::cout << "ERROR IN PLAYER_INIT FILE! ERROR IN PLAYER NUMBER " << playerNumber << std::endl;
            }
            sol->feedMeWithDestinations(PointsFactory::makePoints(pointStr[index],_battlefield->getHeight(),_battlefield->getWidth()));
            index++;
        }

        for(auto &iter : pointStr) std::cout << iter << std::endl;

    }



    return player;
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
    if (attacker->attack(target)){
        killSoldier(target);
        std::cout << "\t\t\t\t" << *attacker << " killed " << *target << std::endl;
    }
}

Battlefield Game::getBattlefield() {
    return *_battlefield;
}

std::vector<Player *> Game::getAllPlayers(){
    return _players;
}

Point Game::getBattlefieldLimits() {
    return Point(_battlefield->getWidth(),_battlefield->getHeight());
}

void Game::killSoldier(Soldier *soldier) {
    soldier->_isAlive = false;
    soldier->setLocation(UNREACHABLE_POINT);
}
