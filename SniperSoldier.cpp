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