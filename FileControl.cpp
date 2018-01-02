//
// Created by damir on 02-Jan-18.
//

#include <iostream>
#include "FileControl.h"

FileControl::FileControl() {
    _outputGame.open("csvs/init_file.csv", std::iostream::out | std::iostream::trunc);
    _isValid = _outputGame.is_open();
}

bool FileControl::isValid() {
    return _isValid;
}

void FileControl::writeInit() {

    _outputGame << "Game" << std::endl;

    _outputGame << "battlefieldSize,";

    std::cout << "Enter battlefield height: ";
    std::string input;
    std::cin >> input;

    _outputGame << input << ",";

    std::cout << "Enter battlefield width: ";
    std::cin >> input;
    _outputGame << input << std::endl;


    _outputGame << "players,";
    std::cout << "Enter number of players (between 2 and 4): ";
    std::cin >> input;
    int numberOfPlayers = std::stoi(input);

    if (numberOfPlayers < 2 || numberOfPlayers > 4) {
        std::cout << "Illegal number. I chose 2 players for you." << std::endl;
        numberOfPlayers = 2;
    }

    _outputGame << input << std::endl;



    _outputGame << "soldiers,";
    std::cout << "Enter number of soldiers per player:";
    std::cin >> input;
    _outputGame << input << std::endl;

    int numberOfSoldiers = std::stoi(input);

    for (int i = 0; i < numberOfPlayers; ++i) {
        std::cout << "Enter player name:";
        std::cin >> input;
        _outputGame << input;

        std::cout << "Enter player type (human/computer):";
        std::cin >> input;
        _outputGame << "," << input;

        if (input == "computer") {
            std::cout << "Enter computer strategy (prefer 0):";
            std::cin >> input;
            _outputGame << "," << input;
        }
        else {

            writePlayer(i, numberOfSoldiers);
        }

        _outputGame << std::endl;

        for (int j = 0; j < numberOfSoldiers; ++j) {

            std::cout << "Enter soldier type (sniper/normal/paramedic):";
            std::cin >> input;
            _outputGame << input;

            std::string soldierType = input;

            std::cout << "Enter starting point:\nX: ";
            std::cin >> input;
            _outputGame << ",[" << input << " ";
            std::cout << "Y: ";
            std::cin >> input;
            _outputGame << input << "]";

            if (soldierType != "paramedic") {
                std::cout << "Enter weapon for soldier (M16/UZI/Missile):";
                std::cin >> input;
                _outputGame << "," << input;
            }

            _outputGame << std::endl;


        }
    }

    _outputGame << "Objects" << std::endl;

    std::cout << "Do you want to add an object? (yes/no)";
    std::cin >> input;

    std::string enterMore = input;

    while (enterMore == "yes") {

        std::cout << "Enter object type (Armor/weapon/solid):";
        std::cin >> input;

        if (input == "weapon") {
            _outputGame << input << ",";

            std::cout << "Enter weapon name: (M16/UZI/Missile)";
            std::cin >> input;
            _outputGame << input;

            std::cout << "Enter starting point: ";
            inputPoint(_outputGame);


            _outputGame << std::endl;
        }
        else if (input == "Armor") {
            _outputGame << input << ",";

            std::cout << "Enter weapon name: (ShieldArmor/BodyArmor)";
            std::cin >> input;
            _outputGame << input;

            std::cout << "Enter defense power: (In range [0.65, 1])";
            std::cin >> input;
            _outputGame << "," << input;

            std::cout << "Enter starting point:\n ";

            _outputPlayer << ",";
            inputPoint(_outputGame);


            _outputGame << std::endl;
        }
        else if (input == "solid") {
            _outputGame << input << ",";

            std::cout << "Enter solid object name: (Building/Tree)";
            std::cin >> input;
            _outputGame << input;

            std::cout << "Enter height:";
            std::cin >> input;
            _outputGame << "," << input;

            std::cout << "Enter width:";
            std::cin >> input;
            _outputGame << "," << input;

            std::cout << "Enter starting point:\nX: ";
            inputPoint(_outputGame);



            _outputGame << std::endl;
        }


        std::cout << "Do you want to add an object? (yes/no)";
        std::cin >> enterMore;
    }



    _outputGame.close();
    _isValid = false;
}

void FileControl::writePlayer(int playerNumber, int numOfSoldiers) {

    std::string fileName = "csvs/player" + std::to_string(playerNumber) + "_file.csv";
    _outputPlayer.open(fileName, std::ofstream::out | std::ofstream::trunc);

    if (! _outputPlayer.is_open()) {
        std::cerr << "Error creating/writing to " << fileName << std::endl;
        return;
    }

    _outputPlayer << "Player" << std::endl;

    std::string input;
    int numOfPoints = 0;
    std::cout << "Enter number of points:";
    std::cin >> numOfPoints;

    for (int i = 0; i < numOfSoldiers; ++i) {
        std::cout << "Soldier number " << (i + 1) << ":" << std::endl;
        for (int j = 0; j < numOfPoints ; ++j) {
            std::cout << "Enter point:" << std::endl;
            inputPoint(_outputPlayer);
        }
        _outputPlayer << std::endl;
    }

}

FileControl::~FileControl() {
    if (_outputGame.is_open()) {
        _outputGame.close();
    }
    if (_outputPlayer.is_open()) {
        _outputPlayer.close();
    }
}

void FileControl::inputPoint(std::ofstream &os) {
    std::string input;
    std::cout << "\nX: ";
    std::cin >> input;
    os << "[" << input << " ";
    std::cout << "Y: ";
    std::cin >> input;
    os << input << "],";
}
