//
// Created by damir on 27-Dec-17.
//

#include "FileParser.h"

FileParser::FileParser(std::string path) {
    file.open(path);
    if (!file.is_open()) {
        std::cout << "ERROR OPENING THE FILE " << path << std::endl;
    }
}

FileParser::~FileParser() {
    file.close();
}