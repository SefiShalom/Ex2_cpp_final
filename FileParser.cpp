//
// Created by damir on 27-Dec-17.
//

#include "FileParser.h"

FileParser::FileParser(const std::string &path) {
    file.open(path);
    if (!file.is_open()) {
        isOpen = false;
        std::cout << "ERROR OPENING THE FILE " << path << std::endl;
    } else {
        isOpen = true;
    }
}

FileParser::~FileParser() {
    file.close();
}

bool FileParser::isGood() {
    return isOpen;
}
