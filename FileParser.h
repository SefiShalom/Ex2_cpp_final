//
// Created by damir on 27-Dec-17.
//

#ifndef EX2_CPP_SEFI_FILEPARSER_H
#define EX2_CPP_SEFI_FILEPARSER_H


#include <iostream>
#include <fstream>
#include <vector>

/**
 * An abstract class for parsing the CSV files
 */
class FileParser {

protected:
    bool _isOpen;

    std::ifstream file;

public:

    //  Ctor opens the file located at "path"
    explicit FileParser(const std::string &path);

    virtual std::vector<std::vector<std::string>> parse() = 0;

    virtual ~FileParser() = 0;

    bool isOpen();
};


#endif //EX2_CPP_SEFI_FILEPARSER_H
