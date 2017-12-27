//
// Created by damir on 26-Dec-17.
//

#include "Game.h"

Game::Game(){}

Game::~Game(){
    std::vector<MapObject*>::iterator it;
    for( it = _gameMap.begin(); it!= _gameMap.end(); it++) delete *it;
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
