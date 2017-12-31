//
// Created by damir on 27-Dec-17.
//

#ifndef EX2_CPP_SEFI_FILEPARSER_H
#define EX2_CPP_SEFI_FILEPARSER_H


#include <iostream>
#include <fstream>
#include <vector>

class FileParser {

protected:
    bool isOpen;

    std::ifstream file;

public:

    explicit FileParser(const std::string &path);

    virtual std::vector<std::vector<std::string>> parse() = 0;

    virtual ~FileParser() = 0;

    bool isGood();
};


#endif //EX2_CPP_SEFI_FILEPARSER_H
