//
// Created by damir on 02-Jan-18.
//

#ifndef EX2_CPP_SEFI_OUTPUT_H
#define EX2_CPP_SEFI_OUTPUT_H


#include <fstream>
#include "Game.h"


/**
 *  This class gives the output of the game.
 *  Every round of the game, "write(Game)" is invoked to write the events of the round.
 *  Eventually, at the final round, "endGame(Game)" is invoked to write the results.
 */
class Output {

    //  Writes the output CSV file
    std::ofstream _output;

    //  Helps determining if we can write the files properly
    bool _isValid;

    //  Counts the game's rounds
    static int iteration;

public:

    //  Ctor
    Output();

    //  Writes the events of the current round
    void write(Game *game);

    //  Writes the game's results
    void endGame(Game *game);

    //  _isValid "getter"
    bool isValid();

    //  Closes the file stream
    ~Output();

};


#endif //EX2_CPP_SEFI_OUTPUT_H
