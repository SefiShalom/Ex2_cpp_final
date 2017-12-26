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

using namespace std;

int main() {
    srand(time(NULL));// getting the current time for the random function at Fighter


    RegularSoldier reg(Point(0, 5), 1);
    RegularSoldier reg2(Point(0, 5), 1);

//    shared_ptr<RegularSoldier> reg2p = make_shared<RegularSoldier>(RegularSoldier(Point(5, 5), 1));
//    shared_ptr<RegularSoldier> regp = make_shared<RegularSoldier>(RegularSoldier(Point(0, 5), 1));

    M16 *m = new M16(Point(2, 2));
    Missile *miss = new Missile(Point(8, 8));
    BodyArmor *ba = new BodyArmor(Point(1, 5), 0.65);
    ShieldArmor *sa = new ShieldArmor(Point(5, 5), 0.65);

//    shared_ptr<Missile> missile = make_shared<Missile>(Missile(Point(8,8)));
//    shared_ptr<BodyArmor> bodyarmor = make_shared<BodyArmor>(BodyArmor(Point(1,5), 0.65));
//    shared_ptr<ShieldArmor> shield = make_shared<ShieldArmor>(ShieldArmor(Point(5,5), 0.65));

//    reg.pickObject(missile);
//    regp->pickObject(missile);

    reg.pickObject(m);
    reg.pickObject(miss);
    reg.pickObject(sa);


    miss->attackArmor(sa);
    m->attackArmor(sa);

    miss->attackArmor(ba);
    m->attackArmor(sa);

    reg2.pickObject(sa);

//    reg2.pickObject(bodyarmor);
//    reg2.pickObject(shield);
    reg.attack(&reg2);

//    reg2p->pickObject(bodyarmor);
//    reg2p->pickObject(shield);

    for(int i = 0; i < 4; i++)
        reg.attack(&reg2);
//        regp->attack(reg2p);

    reg.setNextDestination(Point(10,10));
    while(reg.isWalking()) reg.walk();

//    delete m;
//    delete miss;
//    delete sa;

    std::cout << "\n\n\n**********MAIN DONE**********" << std::endl;

    return 0;
}