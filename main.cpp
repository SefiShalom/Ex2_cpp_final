#include <iostream>
#include <fstream>
#include "Point.h"
#include "Rifle.h"
#include "SolidObject.h"
#include "Medic.h"
#include "Player.h"
#include "Missile.h"
#include "M16.h"

using namespace std;

int main() {

    Point p(1,1);
    cout << p.get_x() << endl;

    Point p_test = p.nextPoint(2, Point(0,1));
    cout << p_test.get_x() << ", " << p_test.get_y() << endl;

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

    M16 m(new Point(0,0));
    Missile missile(new Point(1,5),100,1);

    BodyArmor ba(new Point(2,9),0.4);
    ShieldArmor sa(new Point(5,0),0.7);

    ba.defend(&m);
    ba.defend(&missile);
    sa.defend(&m);
    sa.defend(&missile);
    m.attackArmor(&sa);


    m.useObject(&medic);
    ba.useObject(&medic);
    sa.useObject(&medic);


    std::cout << "\n\n\n**********MAIN DONE**********"<< std::endl;


    return 0;
}