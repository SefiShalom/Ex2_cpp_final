//
// Created by damir on 25-Dec-17.
//

#include "FileReader.h"

FileReader::FileReader(std::string path) {
    file.open(path);
    if (!file.is_open()) {
        std::cout << "ERROR OPENING THE FILE " << path << std::endl;
    }
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
