//
// Created by damir on 25-Dec-17.
//

#include "FileReader.h"

FileReader::FileReader(std::string path) {
    file.open(path);
    if (!file.is_open()) {
        std::cerr << "Error opening the file " << path << std::endl;
        _isOpen = false;
    }
    _isOpen = true;
}

std::string FileReader::getText() {
    std::string tmp;
    while (getline(file, tmp)) {
        text += "\n" + tmp;
    }
    return text;
}

FileReader::~FileReader() {
    file.close();
}

bool FileReader::isOpen() {
    return _isOpen;
}
