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
    std::ifstream file;

public:

    explicit FileParser(std::string path);

    virtual std::vector<std::vector<std::string>> parse() = 0;

    virtual ~FileParser() = 0;
};


#endif //EX2_CPP_SEFI_FILEPARSER_H
