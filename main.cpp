#include <iostream>
#include <fstream>

#include "Point.h"
#include "Rifle.h"
#include "SolidObject.h"
#include "Medic.h"
#include "Player.h"


using namespace std;

int main() {

    Point p(1,1);
    cout << p.get_x() << endl;

    Point p_test = p.nextPoint(2, Point(0,1));
    cout << p_test.get_x() << ", " << p_test.get_y() << endl;

    Rifle rifle(&p,50,1);

    SolidObject so(&p,100,100);

    Medic medic(p, 120, 4, 1);
    medic.whoAreYou();


    fstream player_file;
//    player_file.open("./csvs/player1_file_example.csv");
//    player_file.open("csvs/test.txt");
    player_file.open("csvs/player_init_ex.csv");

//    char buff[1024];
//    cout << player_file.eof() << endl;

////    while (!player_file.eof()) {
//        player_file.getline(buff, 256);
//        cout << buff << endl;
////    }

//    std::ifstream filein("Hey.txt");
    cout << "Is playerfile open? " << (player_file.is_open() ? "Yes" : "No") << endl;

    for (std::string line; std::getline(player_file, line); ) {
        std::cout << line << std::endl;
    }

    Player player("Damir");

    cout << medic << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}