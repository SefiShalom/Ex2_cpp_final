//
// Created by damir on 25-Dec-17.
//

#ifndef EX2_CPP_SEFI_FILEREADER_H
#define EX2_CPP_SEFI_FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>


/**
 *  A class which helps reading a file using file stream
 */
class FileReader {

    std::ifstream file;

    std::string text;

    bool _isOpen;

public:

    //  Ctor opens the file located at "path"
    explicit FileReader(std::string path);

    //  Fetches all of the text from the file
    std::string getText();

    ~FileReader();

    bool isOpen();
};


#endif //EX2_CPP_SEFI_FILEREADER_H
