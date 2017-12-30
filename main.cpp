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

using namespace std;

int main() {

    srand(time(NULL));// getting the current time for the random function at Fighter



//    GameFileParser gfp("csvs/init_file_example2.csv");
////    gfp.parse();
//
//    vector<vector<string>> parseMat = gfp.parse();
//
//    for (auto &i : parseMat) {
//        cout << "\n--This line is of length " << i.size() << endl;
//        cout << "The last element is " << i[i.size()-1] << endl;
//        cout << "Its length is " << i[i.size()-1].size() << endl;
//        for (auto &j : i) {
//            cout << j << endl;
//        }
//    }
//
//    cout << "Battlefield size: (" << stoi(parseMat[1][1]) << ", " << stoi(parseMat[1][2]) << ")" << endl;
//
//    cout << "Got a vector of size " << parseMat.size() << endl;
//


    Game game;

    cout << "\n\n\n" << endl;
    game.initGame("csvs/init_file_example.csv");


//    StatePrinter::print(game);


    std::cout << "\n\n\n**********MAIN DONE**********" << std::endl;

    return 0;
}