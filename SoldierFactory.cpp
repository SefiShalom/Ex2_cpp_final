//
// Created by damir on 26-Dec-17.
//

#include "SoldierFactory.h"
#include "RegularSoldier.h"
#include "SniperSoldier.h"
#include "Medic.h"

#define REGULAR_SOLDIER 1
#define SNIPER_SOLDIER 2
#define MEDIC_SOLDIER 3

long SoldierFactory::id = 1;

std::shared_ptr<Soldier>
SoldierFactory::makeSoldier(const long id, const Point &currPosition, double hp, double speed, const short army,
                            const short type) {
    switch (type) {

        case REGULAR_SOLDIER:
            return std::make_shared<RegularSoldier>(RegularSoldier(/*id++,*/currPosition, army));
        case SNIPER_SOLDIER:
//            return std::make_shared<SniperSoldier>(SniperSoldier(/*id++,*/currPosition, army));
        case MEDIC_SOLDIER:
//            return std::make_shared<Medic>(Medic(/*id++,*/currPosition, army));
        default:
            return nullptr;

    }
}
