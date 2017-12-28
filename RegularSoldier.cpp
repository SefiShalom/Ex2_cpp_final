//
// Created by Sefi on 24/12/2017.
//

#include "RegularSoldier.h"

RegularSoldier::RegularSoldier(const Point& position, const short army)
        : Fighter(position,REGULAR_SOLDIER_HP,REGULAR_SOLDIER_SPEED,army){}

void RegularSoldier::healMe() {
    refillHP(REGULAR_SOLDIER_HP);
}

RegularSoldier::~RegularSoldier() {
//    std::cout << "RegularSoldier dtor" << std::endl;
}


double RegularSoldier::calculateHitChance(Soldier* enemy) const{
    double dist = getLocation().distance(enemy->getLocation());
    std::cout<< "Enemy is " << dist << " meters away" <<std::endl;
    return 1/dist;
}

void RegularSoldier::walk() {
    if (getHP() < 30) {
        Soldier::walk(REGULAR_SOLDIER_SPEED / 2);
        std::cout << "WALKING SLOWLY" << std::endl;
    } else {
        if (getLocation().distance(_nextDestination) > REGULAR_SOLDIER_SPEED * 4) {
            run();
            reduceHP(10);
        } else {
            Soldier::walk(REGULAR_SOLDIER_SPEED);
            std::cout << "WALKING LIKE A DECENT MAN" << std::endl;
        }
    }

}

void RegularSoldier::run() {
    Soldier::walk(REGULAR_SOLDIER_RUNNING_SPEED);
    std::cout << "RUNNING" << std::endl;
}


std::ostream &RegularSoldier::toString(std::ostream &out) {
    out<< "RegularSoldier:" <<std::endl;
    out<< "Army: " << getArmy() <<std::endl;
    out<< "Location: " << getLocation() <<std::endl;
    out<< "HP: " << getHP() <<std::endl;
    return out;
}