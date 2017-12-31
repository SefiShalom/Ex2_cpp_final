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

class GameFileParser : public FileParser {

    bool checkLineNumber(int &number, std::string &str);

public:

    explicit GameFileParser(const std::string &path);

    virtual std::vector<std::vector<std::string>> parse();

    std::string differenceFinderHelper(std::string &str);
};


#endif //EX2_CPP_SEFI_GAMEFILEPARSER_H
