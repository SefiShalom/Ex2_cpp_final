//
// Created by damir on 02-Jan-18.
//

#ifndef EX2_CPP_SEFI_FILECONTROL_H
#define EX2_CPP_SEFI_FILECONTROL_H


#include <fstream>

class FileControl {

    std::ofstream _outputGame;

    std::ofstream _outputPlayer;

    bool _isValid;

    void inputPoint(std::ofstream &out);

public:

    FileControl();

    bool isValid();

    void writeInit();

    void writePlayer(int playerNumber, int numOfSoldiers);

    ~FileControl();
};


#endif //EX2_CPP_SEFI_FILECONTROL_H
