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

using namespace std;

int main() {

    srand(time(NULL));// getting the current time for the random function at Fighter


    RegularSoldier reg(Point(0, 5), 1);
    SniperSoldier sniper(Point(4, 5), 2);
    Medic med1(Point(5,2),1);
    Medic med2(Point(10,10),2);

    M16 *m = new M16(Point(2, 2));
    Missile *miss = new Missile(Point(8, 8));
    BodyArmor *ba = new BodyArmor(Point(1, 5), 0.65);
    ShieldArmor *sa = new ShieldArmor(Point(5, 5), 0.65);
    SolidObject * so = new SolidObject(Point(8,8),10,10);

    /*
    NOTE:
    In order to perform an action on an instance. the instance has
    to accept the action you perform on it. instance->acceptAction(performer);
   */

    m->acceptAction(&sniper); //sniper picked an M16
    miss->acceptAction(&reg);//reg picked a Missile
    ba->acceptAction(&sniper);// sniper picked a BodyArmor
    sa->acceptAction(&reg); // reg picked a ShieldArmor
    reg.acceptAction(&sniper);//reg was attacked by sniper
    sniper.acceptAction(&reg);
    so->acceptAction(&reg);

    reg.acceptAction(&med1);
    sniper.acceptAction(&med2);
    med1.acceptAction(&reg);

    for(int i = 0; i < 4; i++)
        reg.acceptAction(&sniper);


    reg.setNextDestination(Point(10,10));
    while(reg.isWalking()) reg.walk();

    delete m;
    delete miss;
    delete sa;
    delete ba;
    delete so;

    std::cout << "\n\n\n**********MAIN DONE**********" << std::endl;

    return 0;
}