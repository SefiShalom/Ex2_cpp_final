//
// Created by Sefi on 22/12/2017.
//

#include "SniperSoldier.h"
#include "SniperStrategy.h"


SniperSoldier::SniperSoldier(const Point &location, short army)
        : Fighter(location,SNIPER_SOLDIER_HP,SNIPER_SOLDIER_SPEED,army){}


void SniperSoldier::walk() {
    if (getHP() < 30) {
        Soldier::walk(SNIPER_SOLDIER_SPEED / 2);
    } else {
        Soldier::walk(SNIPER_SOLDIER_SPEED);
    }

}

int SniperSoldier::getType() {
    return SNIPER_SOLDIER_IDENTIFIER;
}


double SniperSoldier::calculateHitChance(Soldier* enemy) const{
    double dist = getLocation().distance(enemy->getLocation());
    if(dist == 0) return 0;
    double hitChance = (dist-1)/dist;
    std::cout<< "Enemy is " << dist << " meters away" <<std::endl;
    std::cout<< "HitChance: " << hitChance <<std::endl;
    return hitChance;
}

void SniperSoldier::healMe() {
    refillHP(SNIPER_SOLDIER_HP);
}

std::ostream &SniperSoldier::toString(std::ostream &out) {
    double x = getLocation().get_x();
    double y = getLocation().get_y();
    out << "Sniper" << getArmy() << "(" << x << "," << y << ")";
    return out;
}

SoldierStrategy* SniperSoldier::getStrategy() {
    return new SniperStrategy;
}
