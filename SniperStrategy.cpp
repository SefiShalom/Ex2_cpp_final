//
// Created by Sefi on 31/12/2017.
//

#include "SniperStrategy.h"

std::vector<MapObject*> SniperStrategy::applyStrategy(Soldier *soldier, Game *game) {

    std::vector<MapObject*> ret;

    MapObject *retShield = nullptr;
    MapObject *retBodyArmor = nullptr;
    MapObject *retWeapon = nullptr;
    MapObject *retSoldier = nullptr;

    std::vector<CollectableObject *> collectables = game->retrieveCollectablesInRadius(soldier);
    std::vector<Soldier *> soldiers = game->retrieveEnemySoldiers(soldier);

    float bestArmor = 1;
    float bestShield = 1;

    for (auto &it : collectables) {
        if (!soldier->get_bodyarmor() && !soldier->get_shield()) {

            Armor *checker;
            if (checker = dynamic_cast<ShieldArmor *>(it)) {
                if (checker->getDefensePower() < bestShield) {
                    bestShield = checker->getDefensePower();
                    retShield = checker;
                }
            } else if ((checker = dynamic_cast<BodyArmor *>(it)) && bestShield == 1) {
                if (checker->getDefensePower() < bestArmor) {
                    bestArmor = checker->getDefensePower();
                    retBodyArmor = checker;
                }
            }
        }


        if (Weapon *w = dynamic_cast<Weapon*>(it)) {
            if (typeid(w) != typeid(soldier->get_weapon())) {
                retWeapon = w;
            }
        }
    }

    if (retShield) {
        ret.emplace_back(retShield);
    }
    if (retBodyArmor) {
        ret.emplace_back(retBodyArmor);
    }
    if (retWeapon) {
        ret.emplace_back(retWeapon);
    }


    double maxDist = 0;

    for(auto& it : soldiers){
        double distCheck = soldier->getLocation().distance(it->getLocation());
        if(distCheck > maxDist){
            retSoldier = it;
            maxDist = distCheck;
        }
    }

    if (retSoldier) {
        ret.emplace_back(retSoldier);
    }

    return ret;

}

