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

using namespace std;

int main() {

    srand(time(NULL));// getting the current time for the random function at Fighter

    Game game;
    RegularSoldier* reg = new RegularSoldier(Point(0, 0), 1);
    SniperSoldier* sniper = new SniperSoldier(Point(5, 20), 1);
//    Medic* med1 = new Medic(Point(5,2),1);
    Medic* med2 = new Medic(Point(5,5),2);
    M16 *m = new M16(Point(15, 15));
    Missile *miss = new Missile(Point(10, 10));
//    BodyArmor *ba = new BodyArmor(Point(1, 5), 0.65);
//    ShieldArmor *sa = new ShieldArmor(Point(5, 5), 0.65);
//    SolidObject * so = new SolidObject(Point(8,8),10,10);

    game.addMapObject(reg);
    game.addMapObject(sniper);
    game.addMapObject(m);
    game.addMapObject(miss);
//    game.addMapObject(ba);
//    game.addMapObject(sa);
//    game.addMapObject(med1);
    game.addMapObject(med2);
//    game.addMapObject(so);

    sniper->setNextDestination(Point(5,0));

    while(sniper->isWalking()) {
        sniper->walk();

        std::vector<MapObject *> obj = game.retrieveObjectsInRadius(sniper, 4);

        std::cout << "Objects found in radius 4 around Location: "
                  << sniper->getLocation() << std::endl;

        for(auto it = obj.begin();it < obj.end(); it++)
            std::cout << *(*it);

        for(auto it = obj.begin();it < obj.end(); it++)
            (*it)->acceptAction(sniper);
    }


    std::cout << (*m);







//    std::cout<< (*med1);



    /*
    NOTE:
    In order to perform an action on an instance, the instance has
    to accept the action you perform on it. instance->acceptAction(&performer);
   */





//    m->acceptAction(sniper); //sniper picked an M16
//    miss->acceptAction(reg);//reg picked a Missile
//    ba->acceptAction(sniper);// sniper picked a BodyArmor
//    sa->acceptAction(reg); // reg picked a ShieldArmor
//    reg->acceptAction(sniper);//reg was attacked by sniper
//    sniper->acceptAction(reg);
//    so->acceptAction(reg);
//
//    reg->acceptAction(med1);
//    sniper->acceptAction(med2);
//    med1->acceptAction(reg);
//
//    for(int i = 0; i < 4; i++)
//        sniper->acceptAction(reg);





//    delete m;
//    delete miss;
//    delete sa;
//    delete ba;
//    delete so;


    GameFileParser gfp("csvs/init_file_example.csv");
//    gfp.parse();

    vector<vector<string>> parseMat = gfp.parse();

//    for (auto &i : parseMat) {
//        cout << "\n--This line is of length " << i.size() << endl;
//        cout << "The last element is " << i[i.size()-1] << endl;
//        cout << "Its length is \n" << i[i.size()-1].size() << endl;
//        for (auto &j : i) {
//            cout << j << endl;
//        }
//    }

    cout << "Got a vector of size " << parseMat.size() << endl;



    std::cout << "\n\n\n**********MAIN DONE**********" << std::endl;

    return 0;
}