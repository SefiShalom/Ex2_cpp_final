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
#include "Medic.h"

Game::Game()
        : _battlefield(nullptr) {}

Game::~Game() {
    std::vector<MapObject *>::iterator it;
    for (it = _gameMap.begin(); it != _gameMap.end(); it++)
        delete *it;
    if (_battlefield) delete _battlefield;      // CAUSES SEGMENTATION FAULT FOR SOME REASON!
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

    for (auto &it : _gameMap) {

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
    if (!gfp.isOpen()) {
        std::cerr << "Error opening the file " << path << std::endl;
        return;
    }
    std::vector<std::vector<std::string>> csv = gfp.parse();

    if (csv[0][0] != "Game" || csv[0].size() != 1) {
        std::cerr << "Error in game-csv in first line" << std::endl;
        return;
    }

    if (csv.size() < 2) {
        std::cerr << "Error in game-csv. No battlefield!" << std::endl;
    }

    if (csv[BATTLEFIELD_LINE].size() != 3) {
        std::cerr << "Error in game-csv in line " << BATTLEFIELD_LINE << " in file " << path << std::endl;
        return;
    }
    _battlefield = new Battlefield(std::stoi(csv[BATTLEFIELD_LINE][1]), std::stoi(csv[BATTLEFIELD_LINE][2]));
    int numOfPlayers = std::stoi(csv[PLAYERS_LINE][1]);
    int numOfSoldiersPerPlayer = std::stoi(csv[NUM_OF_SOLDIERS_LINE][1]);

    int startSearchingObjectsFrom = 4 + (numOfPlayers * (numOfSoldiersPerPlayer + 1));

    if (!addAllMapObject(startSearchingObjectsFrom, csv)) {
        std::cerr << "Error parsing objects!" << std::endl;
        return;
    }

    for (int i = 0; i < numOfPlayers; ++i) {
        int startReadingPlayerInfoFrom = 5 + (numOfSoldiersPerPlayer + 1) * i;

        if (csv[4 + (numOfSoldiersPerPlayer + 1) * i][1] != "computer" && csv[4 + (numOfSoldiersPerPlayer + 1) * i][1] != "human") {
            std::cerr << "Player p" << (i + 1) << " is not a computer nor a human? Impossible!" << std::endl;
            return;
        }
        if ((csv[4 + (numOfSoldiersPerPlayer + 1) * i].size() == 2 && csv[4 + (numOfSoldiersPerPlayer + 1) * i][1] != "human")
            || (csv[4 + (numOfSoldiersPerPlayer + 1) * i].size() == 3 && csv[4 + (numOfSoldiersPerPlayer + 1) * i][1] != "computer")) {
            std::cerr << "Error found in player number " << (i + 1) << std::endl;
            return;
        }

        bool isComputer = csv[4 + (numOfSoldiersPerPlayer + 1) * i][1] == "computer";
        int strat = -1;
        if (isComputer) {
            strat = std::stoi(csv[4 + (numOfSoldiersPerPlayer + 1) * i][2]);
        }

        Player *p_i = generatePlayerWithSoldiers(i, startReadingPlayerInfoFrom, numOfSoldiersPerPlayer, csv,
                                                 strat, isComputer);

        if (p_i == nullptr) {
            std::cerr << "Error creating player!" << std::endl;
            return;
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

    _readyToGo = true;
}

Player *
Game::generatePlayerWithSoldiers(int playerNumber, int startReadingFrom, int numOfSoldiers,
                                 const std::vector<std::vector<std::string>> &csv, int strat, bool isComputer) {

    std::string pc = "Computer";
    std::string human = "Human";

    Player *player;
    if (isComputer) {
        player = new ComputerPlayer(playerNumber, csv[startReadingFrom -1][0] + " | PC"/*pc + std::to_string(playerNumber)*/, strat, _battlefield);
    } else {
        player = new HumanPlayer(playerNumber, csv[startReadingFrom -1][0] + " | HUMAN"/*human + std::to_string(playerNumber)*/);
    }

    int ind = 0;


    for (int i = 0; i < numOfSoldiers; ++i) {
        Soldier *newSoldier = SoldierFactory::makeSoldier(csv[startReadingFrom], playerNumber);
        if (newSoldier == nullptr) {
            std::cerr << "Invalid soldier input!" << std::endl;
            std::cerr << "Error creating a soldier for player number " << (playerNumber + 1) << std::endl;
            return nullptr;
        }
        player->addSoldier(newSoldier);
        ++startReadingFrom;
    }

    if(!isComputer){

        FileReader fr("csvs/player" + std::to_string(playerNumber) + "_file.csv");

        if (!fr.isOpen()) {
            std::cerr << "Error opening the file " << "csvs/player" << std::to_string(playerNumber) << "_file.csv" << std::endl;
            return nullptr;
        }

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

//        for(auto &iter : pointStr) std::cout << iter << std::endl;

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
    std::cout << *attacker << attacker->getID() << " attempting to attack " << *target << target->getID() << std::endl;
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
    soldier->_walking = false;
    soldier->setLocation(UNREACHABLE_POINT);
}

std::vector<Soldier *> Game::retrieveFriendlySoldiers(Soldier *soldier) {
    std::vector<Soldier *> friendlySoldiers;
    for (auto & it : _gameMap) {
        if (Soldier* t = dynamic_cast<Soldier*>(it)) {
            if(t->getArmy() == soldier->getArmy() && t->isAlive() && soldier->getID() != it->getID()){
                friendlySoldiers.emplace_back(t);
            }

        }
    }
    return friendlySoldiers;
}

void Game::applyStrategy(Soldier *soldier, SoldierStrategy *soldierStrategy) {
    std::vector<MapObject*> actions = soldierStrategy->applyStrategy(soldier, this);

    for (auto &it : actions) {
        if (dynamic_cast<Soldier*>(it) && !dynamic_cast<Medic*>(soldier)) {
            attack(soldier, dynamic_cast<Soldier*>(it));
        } else {
            it->acceptAction(soldier);
        }
    }
}

bool Game::play() {

    if (!_readyToGo) {
        std::cerr << "Cannot play! See errors above." << std::endl;
        return false;
    }

    long numOfArmies = _players.size();

    while (numOfArmies >= 2) {
        for (auto &it : _players) {
            if (it->isPlaying()) {
                it->playTurn(this);
            } else {
                numOfArmies--;
                std::cout << "Player " << it->_army << " LOST" << std::endl;
            }
        }
    }

    for (auto &it : _players) {
        if (it->isPlaying()) {
            std::cout << "Player " << it->_army << " WON!" << std::endl;
        }
    }

    return true;
}

bool Game::isReadyToGo() {
    return _readyToGo;
}
