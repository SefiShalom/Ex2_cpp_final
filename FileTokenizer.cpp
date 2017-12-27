//
// Created by damir on 25-Dec-17.
//

#include "FileTokenizer.h"

FileTokenizer::FileTokenizer()
        : toParse("") {}

FileTokenizer::FileTokenizer(std::string text)
        : toParse(text) {}

std::vector<std::string> FileTokenizer::tokenizeBy(std::string delims) {
    std::vector<std::string> ret;

    char *toks = const_cast<char *>(toParse.c_str());

    char *currStr = strtok(toks, delims.c_str());
    while (currStr != NULL) {
        ret.push_back(std::string(currStr));
        currStr = strtok(NULL, delims.c_str());
    }

    return ret;
}

void FileTokenizer::setText(std::string text) {
    toParse = text;
}

