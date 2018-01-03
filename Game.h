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

/**
 *  This is the game class. This is where the magic happens.
 *  This class manages the interactions between every critical component.
 */
class Game {

    //  Contains all of the map objects in the game
    std::vector<MapObject *> _gameMap;

    //  Contains all of the players in the game
    std::vector<Player *> _players;

    //  The field on which the game is happening
    Battlefield *_battlefield;

    bool _readyToGo = false;

public:

    //  Ctor. Initializes _battlefield to nullptr
    Game();

    // Dtor. Deletes all of the allocated memory
    ~Game();

    //  Returns a vector of collectable objects around a given soldier within PICKABLE_RADIUS (2)
    std::vector<CollectableObject *> retrieveCollectablesInRadius(Soldier *soldier);

    //  Adds a map object to the _gameMap vector
    void addMapObject(MapObject *object);

    //  Returns all of the map objects as a vector
    std::vector<MapObject *> &getAllObjects();

    //  Initializes the game. Asks the user if he/she wants to read a game CSV init file from a certain path, or
    //  create a new one, giving the instructed input.
    void initGame();

    //  Performs an attack on the target soldier.
    //  Invokes the attacking soldier's attack method on the target soldier
    void attack(Soldier *attacker, Soldier *target);

    //  Creates a new player:
    //  Params:
    //      playerNumber:       The player's number, which is also its army's number
    //      startReadingFrom:   Tell where to start reading from within the game CSV init file
    //      numOfSoldiers:      Number of soldiers per player
    //      csv:                The vector of vector of string which is the game CSV init file
    //      strat:              Strategy number. Matters only if it is a computer player
    //      isComputer:         Self explanatory
    //      filePath:           The path to the player's CSV file
    Player *generatePlayerWithSoldiers(int playerNumber, int startReadingFrom, int numOfSoldiers,
                                       const std::vector<std::vector<std::string>> &csv, int strat,
                                       bool isComputer = false, std::string filePath = "");

    //  Adds all of the map objects, which do not belong to any soldier, to the _gameMap vector
    //  from the game CSV init file
    bool addAllMapObject(int from, const std::vector<std::vector<std::string>> &csv);

    //  Returns the game's battlefield
    Battlefield getBattlefield();

    //  Returns a vector of map objects which located around a given point within a given radius
    std::vector<MapObject *> retrieveObjectsWithinRadiusByPoint(const Point &point, double radius);

    //  Returns closest object by a given point and radius
    MapObject *getClosestObject(const Point &point, double radius);

    //  Returns a vector of all of the game's players
    std::vector<Player *> getAllPlayers();

    //  Returns battlefield limits
    Point getBattlefieldLimits();

    //  Performs a killing procedure on the given soldier
    void killSoldier(Soldier *pSoldier);

    //  Applies the corresponding strategy of every class which inherits from the Soldier class
    void applyStrategy(Soldier *soldier, SoldierStrategy *soldierStrategy);

    //  Returns a vector of all of the soldiers in the game who are not in the same army of the
    //  given soldier
    std::vector<Soldier *> retrieveEnemySoldiers(Soldier *soldier);

    //  Returns a vector of all of the soldiers in the game who are in the same army of the
    //  given soldier
    std::vector<Soldier *> retrieveFriendlySoldiers(Soldier *soldier);

    //  Iterates through all of the players. Every iteration, every players plays his/her turn.
    //  This function runs while at least two players have more moves left
    bool play();

    //  Determines if everything with the initialization of the game went properly
    bool isReadyToGo();

    //  Returns a vector of objects around a given point within a given radius
    std::vector<SolidObject *> retrieveSolidObjects();

    //  Initializes the game. The files are read from the paths that were given at the command line
    void initGame(std::vector<std::string> arguments);
};


#endif //EX2_CPP_SEFI_GAME_H
