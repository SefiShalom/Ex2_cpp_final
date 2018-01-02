//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_GAME_H
#define EX2_CPP_SEFI_GAME_H

#include "MapObject.h"
#include "Soldier.h"
#include "Battlefield.h"
#include "Player.h"
#include "FileControl.h"
#include <iostream>
#include <vector>


#define BATTLEFIELD_LINE 1
#define PLAYERS_LINE 2
#define NUM_OF_SOLDIERS_LINE 3
#define PICKABLE_RADIUS 2

#define INDEX_OF_POINT_FOR_SOLDIER 1
#define INDEX_OF_POINT_FOR_WEAPON 2
#define INDEX_OF_POINT_FOR_ARMOR 3
#define INDEX_OF_POINT_FOR_SOLID_OBJECT 4


class Game {

    std::vector<MapObject *> _gameMap;// contains all of the MapObjects in the game
    std::vector<Player *> _players;
    Battlefield *_battlefield;

    bool _readyToGo = false;

public:

    Game();

    ~Game();

    std::vector<CollectableObject *> retrieveCollectablesInRadius(Soldier *soldier);

    void addMapObject(MapObject *object);

    std::vector<MapObject *> &getAllObjects();

    void initGame();

    void attack(Soldier *attacker, Soldier *target);

    Player *generatePlayerWithSoldiers(int playerNumber, int startReadingFrom, int numOfSoldiers,
                                       const std::vector<std::vector<std::string>> &csv, int strat,
                                       bool isComputer = false, std::string filePath = "");

    bool addAllMapObject(int from, const std::vector<std::vector<std::string>> &csv);

    Battlefield getBattlefield();

    std::vector<MapObject *> retrieveObjectsWithinRadiusByPoint(const Point &point, double radius);

    MapObject *getClosestObject(const Point &point, double radius);

    std::vector<Player *> getAllPlayers();

    Point getBattlefieldLimits();

    void killSoldier(Soldier *pSoldier);

    void applyStrategy(Soldier *soldier, SoldierStrategy *soldierStrategy);

    std::vector<Soldier *> retrieveEnemySoldiers(Soldier *soldier);

    std::vector<Soldier *> retrieveFriendlySoldiers(Soldier *soldier);

    bool play();

    bool isReadyToGo();

    std::vector<SolidObject *> retrieveSolidObjects();

    void initGame(std::vector<std::string> arguments);
};


#endif //EX2_CPP_SEFI_GAME_H
