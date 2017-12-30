//
// Created by damir on 26-Dec-17.
//

#include "Game.h"
#include "GameFileParser.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "SoldierFactory.h"

Game::Game()
        : _battlefield(nullptr) {}

Game::~Game() {
    std::vector<MapObject *>::iterator it;
    for (it = _gameMap.begin(); it != _gameMap.end(); it++) delete *it;
    delete _battlefield;      // CAUSES SEGMENTATION FAULT FOR SOME REASON!
    for (auto &p : _players) {
        delete(p);
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

    // Player p_i = GenerateSoldiersForPlayer(int playerNumber, int startReadingFrom, int numOfSoldiers, bool isComputer = false);

//    for (int i = 0; i < csv.size(); ++i) {
//        for (int j = 0; j < csv[i].size(); ++j) {
//            std::cout << "i = " << i << ", j = " << j << "\ncsv[i][j] = " << csv[i][j] << std::endl;
//        }
//    }

    for (int i = 0; i < numOfPlayers; ++i) {
        int startReadingPlayerInfoFrom = 5 + (numOfSoldiersPerPlayer + 1) * i;

//        for (const auto &j : csv[startReadingPlayerInfoFrom]) {
//            std::cout << j << std::endl;
//        }
        bool isComputer = csv[4 + (numOfSoldiersPerPlayer  + 1) * i][1] == "computer";

//        std::cout << csv[4 + numOfSoldiersPerPlayer *i][1] << std::endl;

        Player *p_i = generatePlayerWithSoldiers(i, startReadingPlayerInfoFrom, numOfSoldiersPerPlayer, csv, isComputer);

        if (p_i == nullptr) {
            std::cout << "Error creating player!" << std::endl;
        }

        std::cout << "Created a player: " << *p_i << std::endl;

        _players.emplace_back(p_i);
    }

    // CONTINUE FROM HERE

}

Player *
Game::generatePlayerWithSoldiers(int playerNumber, int startReadingFrom, int numOfSoldiers,
                                 const std::vector<std::vector<std::string>> &csv, bool isComputer) {

    std::string pc    = "Computer";
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

//    std::cout << "Created player:"
    //CONTINUE FROM HERE!


    return player;


}

void Game::killSoldier(Soldier *soldier) {

    std::vector<MapObject *> objects = soldier->kill();

//    std::vector<MapObject*>::iterator i,j;

    auto i = objects.begin();
    auto j = _gameMap.begin();

    while (i != objects.end())
        while (j != _gameMap.end())
            if (*i != *j) {
                delete *i;
                _gameMap.erase(j);
            }
}



