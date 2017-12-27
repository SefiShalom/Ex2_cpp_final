//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_GAME_H
#define EX2_CPP_SEFI_GAME_H

#include "MapObject.h"
#include "Soldier.h"
#include <iostream>
#include <vector>

class Game {

    std::vector<MapObject*> _gameMap;// contains all of the MapObjects in the game

public:

    Game();

    ~Game();

    std::vector<MapObject*> retrieveObjectsInRadius(Soldier* soldier, double radius);

    void addMapObject(MapObject* object);

    std::vector<MapObject*>& getAllObjects();
};


#endif //EX2_CPP_SEFI_GAME_H
