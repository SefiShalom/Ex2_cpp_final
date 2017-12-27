//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_GAME_H
#define EX2_CPP_SEFI_GAME_H

#include "MapObject.h"
#include "Soldier.h"
#include "Battlefield.h"
#include <iostream>
#include <vector>


#define BATTLEFIELD_LINE 1
#define PLAYERS_LINE 2
#define NUM_OF_SOLDIERS_LINE 3
#define INDEX_OF_POINT_FOR_SOLDIER 1
#define INDEX_OF_POINT_FOR_WEAPON 2
#define INDEX_OF_POINT_FOR_ARMOR 3
#define INDEX_OF_POINT_FOR_SOLID_OBJECT 4


class Game {

    std::vector<MapObject*> _gameMap;// contains all of the MapObjects in the game

    Battlefield* _battlefield;

public:

    Game();

    ~Game();

    std::vector<MapObject*> retrieveObjectsInRadius(Soldier* soldier, double radius);

    void addMapObject(MapObject* object);

    std::vector<MapObject*>& getAllObjects();

    void initGame(std::string path);
};


#endif //EX2_CPP_SEFI_GAME_H
