//
// Created by damir on 25-Dec-17.
//

#ifndef EX2_CPP_SEFI_FILETOKENIZER_H
#define EX2_CPP_SEFI_FILETOKENIZER_H


#include <string>
#include <vector>
#include <cstring>


/**
 *  Acts like Java's StringTokenizer.
 *  This class receives text as input, and splits it to a string of vectors by given delimiters.
 */
class FileTokenizer {

    std::string toParse;

public:

    FileTokenizer();

    //  Ctor which receives text as its argument
    explicit FileTokenizer(std::string text);

    //  Splits the string to a vector of strings by delimiters
    std::vector<std::string> tokenizeBy(std::string delims);

    //  Changes the input text
    void setText(std::string text);

};


#endif //EX2_CPP_SEFI_FILETOKENIZER_H
