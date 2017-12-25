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
    return 1 / (getLocation().distance(enemy->getLocation()));
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

double RegularSoldier::calculateHitChance(std::shared_ptr<Soldier> enemy) const {
    return 1 / (getLocation().distance(enemy->getLocation()));
}
