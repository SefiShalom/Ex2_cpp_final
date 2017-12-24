#include <iostream>
#include <fstream>
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


    RegularSoldier* reg = new RegularSoldier(new Point(0,5),1);

    M16* m = new M16(new Point(2,2));
    Missile* miss = new Missile(new Point(8,8));

    reg->pickObject(m);
    reg->pickObject(miss);

    delete reg;
    delete m;

    std::cout << "\n\n\n**********MAIN DONE**********"<< std::endl;

    return 0;
}