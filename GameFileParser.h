//
// Created by damir on 27-Dec-17.
//

#ifndef EX2_CPP_SEFI_GAMEFILEPARSER_H
#define EX2_CPP_SEFI_GAMEFILEPARSER_H

#include "FileParser.h"

#define GAME_NO 1
#define BATTLEFIELD_NO 2
#define PLAYERS_NO 3
#define SOLDIERS_NO 4
#define P_NO 5
#define OBJECTS_NO 6


/**
 *  This class parses the game CSV init file.
 */
class GameFileParser : public FileParser {

    bool checkLineNumber(int &number, std::string &str);

public:

    //  Ctor which receives a path to the game CSV init file
    explicit GameFileParser(const std::string &path);

    //  Returns a vector of vector of strings if every line is where it should be, according to the examples
    //  that were given with the exercise.
    virtual std::vector<std::vector<std::string>> parse();

};


#endif //EX2_CPP_SEFI_GAMEFILEPARSER_H
