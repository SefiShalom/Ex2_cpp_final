//
// Created by Sefi on 31/12/2017.
//

#include "RegularSoldierStrategy.h"
#include "CollectableObject.h"
#include "Game.h"

std::vector<MapObject*> RegularSoldierStrategy::applyStrategy(Soldier *soldier, Game *game) {

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


    double minDist = INFINITY;

    std::vector<SolidObject*> solids = game->retrieveSolidObjects();

    for(auto& it : soldiers){
        double distCheck = soldier->getLocation().distance(it->getLocation());

        bool isLineClear = true;

        for(auto& solidIt: solids){
            if(solidIt->isBetween(soldier->getLocation(),it->getLocation())){
                isLineClear =  false;
                break;
            }
        }

        if(distCheck < minDist && isLineClear){
            retSoldier = it;
            minDist = distCheck;
        }
    }

    if (retSoldier) {
        ret.emplace_back(retSoldier);
    }

    return ret;

}

RegularSoldierStrategy::~RegularSoldierStrategy() {}
