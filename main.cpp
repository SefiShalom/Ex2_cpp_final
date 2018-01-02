#include <iostream>
#include <fstream>

#include <memory>

#include "Point.h"
#include "Rifle.h"
#include "SolidObject.h"
#include "Medic.h"
#include "Player.h"
#include "Missile.h"
#include "M16.h"
#include "RegularSoldier.h"
#include "SniperSoldier.h"
#include "Game.h"
#include "GameFileParser.h"
#include "StatePrinter.h"
#include "HumanPlayer.h"

using namespace std;

int main(int argc, char *argv[]) {

    srand(time(NULL));

    Game game;

    if (argc > 1) {

        string choice;

        vector<string> arguments;

        if (((string)argv[1]) == "-help" && argc == 2) {
            cout << "[initFile] [player1 player2 ...]" << endl;
        }
        else {

            if (argc <= 2) {
                cerr << "Invalid arguments! Exiting." << endl;
            }
            else {

                for (int i = 1; i < argc; ++i) {
                    arguments.emplace_back((string)argv[i]);
                }

                game.initGame(arguments);
//                StatePrinter::print(game);
                game.play();
//                StatePrinter::print(game);
            }

        }

    }
    else {

        cout << "\n\n\n" << endl;
        game.initGame();

//        StatePrinter::print(game);
        game.play();
//        StatePrinter::print(game);

    }

    std::cout << "\n\n\n**********MAIN DONE**********" << std::endl;


    return 0;
}