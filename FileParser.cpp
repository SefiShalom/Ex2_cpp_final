//
// Created by damir on 27-Dec-17.
//

#include "FileParser.h"

FileParser::FileParser(const std::string &path) {
    file.open(path);
    if (!file.is_open()) {
        _isOpen = false;
        std::cerr << "ERROR OPENING THE FILE " << path << std::endl;
    } else {
        _isOpen = true;
    }
}

FileParser::~FileParser() {
    file.close();
}

bool FileParser::isOpen() {
    return _isOpen;
}
