//
// Created by damir on 26-Dec-17.
//

#include <vector>
#include "MedicStrategy.h"
#include "CollectableObject.h"

#include "Game.h"

std::vector<MapObject*> MedicStrategy::applyStrategy(Soldier *soldier, Game *game) {

    std::vector<MapObject*> ret;

    MapObject *retShield = nullptr;
    MapObject *retBodyArmor = nullptr;



    std::vector<CollectableObject *> collectables = game->retrieveCollectablesInRadius(soldier);
    std::vector<Soldier *> enemies = game->retrieveEnemySoldiers(soldier);
    std::vector<Soldier *> friends = game->retrieveFriendlySoldiers(soldier);

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
    }

    if (retShield) {
        ret.emplace_back(retShield);
    }
    if (retBodyArmor) {
        ret.emplace_back(retBodyArmor);
    }

    for(auto& it : friends){
        double distCheck = soldier->getLocation().distance(it->getLocation());
        if(distCheck <= 1){
            ret.emplace_back(it);
            return ret;
        }
    }

    for(auto& it : enemies){
        double distCheck = soldier->getLocation().distance(it->getLocation());
        if(distCheck <= 1){
            ret.emplace_back(it);
            return ret;
        }
    }


    return ret;
}

MedicStrategy::~MedicStrategy() {

}
