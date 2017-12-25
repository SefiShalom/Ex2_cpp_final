//
// Created by damir on 25-Dec-17.
//

#ifndef EX2_CPP_SEFI_FILETOKENIZER_H
#define EX2_CPP_SEFI_FILETOKENIZER_H


#include <string>
#include <vector>
#include <cstring>

class FileTokenizer {

    std::string toParse;

public:

    explicit FileTokenizer(std::string text);

    std::vector<std::string> tokenizeBy(std::string delims);

};


#endif //EX2_CPP_SEFI_FILETOKENIZER_H
