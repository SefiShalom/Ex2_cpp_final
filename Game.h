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
    std::vector<Player *> _players;// contains all of the Players in the game
    Battlefield *_battlefield;// The field on which the game is happening

    bool _readyToGo = false;

public:

    //ctor. Does not receive arguments
    Game();

    //dtor
    ~Game();

    //Returns a std::vector<CollectableObject*> around a given soldier within a PICKABLE_RADIUS
    std::vector<CollectableObject *> retrieveCollectablesInRadius(Soldier *soldier);

    //Adds a MapObject* to the _gameMap vector
    void addMapObject(MapObject *object);

    //returns the _gameMap
    std::vector<MapObject *> &getAllObjects();


    void initGame();

    //performs an attack on the 'target'
    //invokes the 'attacker' attack method on the 'target'
    void attack(Soldier *attacker, Soldier *target);


    Player *generatePlayerWithSoldiers(int playerNumber, int startReadingFrom, int numOfSoldiers,
                                       const std::vector<std::vector<std::string>> &csv, int strat,
                                       bool isComputer = false, std::string filePath = "");

    bool addAllMapObject(int from, const std::vector<std::vector<std::string>> &csv);


    Battlefield getBattlefield();

    //Returns a std::vector<MapObject*> of objects around a given point within a given radius
    std::vector<MapObject *> retrieveObjectsWithinRadiusByPoint(const Point &point, double radius);

    //Returns a pointer of the closest object by a given point and radius
    MapObject *getClosestObject(const Point &point, double radius);

    std::vector<Player *> getAllPlayers();

    Point getBattlefieldLimits();

    //Performs a killing procedure on the given soldier
    void killSoldier(Soldier *pSoldier);


    void applyStrategy(Soldier *soldier, SoldierStrategy *soldierStrategy);


    //Returns a std::vector<Soldir*> of all the soldiers in the game who are not in the same army of the
    //given soldier
    std::vector<Soldier *> retrieveEnemySoldiers(Soldier *soldier);

    //Returns a std::vector<Soldir*> of all the soldiers in the game who are in the same army of the
    //given soldier
    std::vector<Soldier *> retrieveFriendlySoldiers(Soldier *soldier);

    bool play();

    bool isReadyToGo();

    //Returns a std::vector<MapObject*> of objects around a given point within a given radius
    std::vector<SolidObject *> retrieveSolidObjects();

    void initGame(std::vector<std::string> arguments);
};


#endif //EX2_CPP_SEFI_GAME_H
