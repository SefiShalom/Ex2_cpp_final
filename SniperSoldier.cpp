//
// Created by Sefi on 22/12/2017.
//

#include "SniperSoldier.h"


SniperSoldier::SniperSoldier(const Point &location, short army)
        : Fighter(location,army,SNIPER_SOLDIER_HP,SNIPER_SOLDIER_SPEED){}

double SniperSoldier::calculateHitChance(Soldier &enemy) const {
    double dist = _position.distance(enemy.getLocation());
    return dist/(dist-1);
}

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

double SniperSoldier::calculateHitChance(std::shared_ptr<Soldier> enemy) {
    double dist = _position.distance(enemy->getLocation());
    return (dist-1)/dist;
}

double SniperSoldier::calculateHitChance(Soldier* enemy) const{
    double d = getLocation().distance(enemy->getLocation());
    return d-1 / d;
}

void SniperSoldier::healMe() {
    refillHP(SNIPER_SOLDIER_HP);
}

std::ostream &SniperSoldier::toString(std::ostream &out) {
    out<< "SniperSoldier:" <<std::endl;
    out<< "Army: " << getArmy() <<std::endl;
    out<< "Location: " << getLocation() <<std::endl;
    out<< "HP: " << getHP() <<std::endl;
    return out;
}
