//
// Created by damir on 27-Dec-17.
//

#include <sstream>
#include <utility>
#include "GameFileParser.h"
#include "FileTokenizer.h"


GameFileParser::GameFileParser(const std::string &path)
        : FileParser(std::move(path)) {}

std::vector<std::vector<std::string>> GameFileParser::parse() {

    std::string tmp;

    std::vector<std::vector<std::string>> ret;
    std::vector<std::string> line;

    FileTokenizer ft;

    int lineNumber = 1;
    while (getline(file, tmp)) {

        ft.setText(tmp);
        line = ft.tokenizeBy(",\n\r\b\t");

        if (lineNumber < OBJECTS_NO && lineNumber > 0) {
            if (!checkLineNumber(lineNumber, line[0])) {
                std::cout << std::endl;
                std::cout << "Error on game.csv. Error line: " << lineNumber << std::endl;
                std::cout << "Found the word " << line[0].c_str() << std::endl;

                return std::vector<std::vector<std::string>>();
            }
        }
        ret.emplace_back(line);
        lineNumber++;
    }
    return ret;
}


bool GameFileParser::checkLineNumber(int &number, std::string &str) {

    switch (number) {

        case GAME_NO:
            return str == "Game";

        case BATTLEFIELD_NO:
            return str == "battlefieldSize";

        case PLAYERS_NO:
            return str == "players";

        case SOLDIERS_NO:
            return str == "soldiers";

        case P_NO:
            return str[0] == 'p';

        case OBJECTS_NO:
            return str == "Objects";

        default:
            break;
    }

    return false;
}
