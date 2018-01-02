//
// Created by damir on 02-Jan-18.
//

#ifndef EX2_CPP_SEFI_OUTPUT_H
#define EX2_CPP_SEFI_OUTPUT_H


#include <fstream>
#include "Game.h"

class Output {

    std::ofstream _output;

    bool _isValid;

    static int iteration;

public:

    Output();

    void write(Game *game);

    void endGame(Game *game);

    bool isValid();

    ~Output();

};


#endif //EX2_CPP_SEFI_OUTPUT_H
