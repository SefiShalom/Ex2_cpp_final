//
// Created by damir on 25-Dec-17.
//

#ifndef EX2_CPP_SEFI_FILEREADER_H
#define EX2_CPP_SEFI_FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>

class FileReader {

    std::ifstream file;

    std::string text;

public:

    explicit FileReader(std::string path);

    std::string getText();

    ~FileReader();
};


#endif //EX2_CPP_SEFI_FILEREADER_H
