//
// Created by Sefi on 31/12/2017.
//

#include "SniperStrategy.h"

MapObject *SniperStrategy::applyStrategy(Soldier *soldier, Game *game) {

    MapObject *object;

    std::vector<CollectableObject *> collectables = game->retrieveCollectablesInRadius(soldier);
    std::vector<Soldier *> soldiers = game->retrieveEnemySoldiers(soldier);

    float bestArmor = 1;
    float bestShield = 1;

    MapObject *ret = nullptr;

    for (auto &it : collectables) {
        if (!soldier->get_bodyarmor() && !soldier->get_shield()) {

            Armor *checker;
            if (checker = dynamic_cast<ShieldArmor *>(it)) {
                if (checker->getDefensePower() < bestShield) {
                    bestShield = checker->getDefensePower();
                    ret = checker;
                }
            } else if ((checker = dynamic_cast<BodyArmor *>(it)) && bestShield == 1) {
                if (checker->getDefensePower() < bestArmor) {
                    bestArmor = checker->getDefensePower();
                    ret = checker;
                }
            }
        }


        if (Weapon *w = dynamic_cast<Weapon*>(it)) {
            if (typeid(w) != typeid(soldier->get_weapon())) {
                ret = w;
            }
        }
    }

    if(ret){
        return ret;
    }


    double maxDist = 0;

    for(auto& it : soldiers){
        double distCheck = soldier->getLocation().distance(it->getLocation());
        if(distCheck > maxDist){
            ret = it;
            maxDist = distCheck;
        }
    }

    return ret;

}

