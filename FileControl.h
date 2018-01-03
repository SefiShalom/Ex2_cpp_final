//
// Created by damir on 02-Jan-18.
//

#ifndef EX2_CPP_SEFI_FILECONTROL_H
#define EX2_CPP_SEFI_FILECONTROL_H


#include <fstream>

/**
 *  This class is dealing with the user interface.
 *  This class allows a user to create his own game CSV init file and player CSV file, asking the right questions.
 *  It will ask a user to input all the information needed.
 */
class FileControl {

    //  Writes the game CSV init file
    std::ofstream _outputGame;

    //  Writes the player CSV file
    std::ofstream _outputPlayer;

    //  Helps determining if we can write the files properly
    bool _isValid;

    //  Outputs a point to the CSV file
    void inputPoint(std::ofstream &out);

public:

    //  Ctor
    FileControl();

    //  _isValid "getter"
    bool isValid();

    //  Writes the game CSV init file
    void writeInit();

    //  Writes the player CSV file
    void writePlayer(int playerNumber, int numOfSoldiers);

    //  Ensures the closing of the file streams
    ~FileControl();
};


#endif //EX2_CPP_SEFI_FILECONTROL_H
