//
// Created by damir on 26-Dec-17.
//

#include "Game.h"
#include "GameFileParser.h"

Game::Game() {}

Game::~Game(){
    std::vector<MapObject*>::iterator it;
    for( it = _gameMap.begin(); it!= _gameMap.end(); it++) delete *it;
//    delete _battlefield;      // CAUSES SEGMENTATION FAULT FOR SOME REASON!
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

void Game::addMapObject(MapObject* object) {
    _gameMap.emplace_back(object);
}

std::vector<MapObject *> &Game::getAllObjects() {
    return _gameMap;
}

void Game::initGame(std::string path) {

    GameFileParser gfp(path);

    std::vector<std::vector<std::string>> csv = gfp.parse();

    _battlefield = new Battlefield(std::stoi(csv[BATTLEFIELD_LINE][1]), std::stoi(csv[BATTLEFIELD_LINE][2]));

    int numOfPlayers          = std::stoi(csv[PLAYERS_LINE][1]);
    int numOfSoldierPerPlayer = std::stoi(csv[NUM_OF_SOLDIERS_LINE][1]);

    int startSearchingObjectsFrom = 4 + (numOfPlayers * (numOfSoldierPerPlayer + 1));

    // Player p_i = GenerateSoldiersForPlayer(int playerNumber, int startReadingFrom, int numOfSoldiers, bool isComputer = false);



    // CONTINUE FROM HERE

}


