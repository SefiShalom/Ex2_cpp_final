//
// Created by damir on 26-Dec-17.
//

#ifndef EX2_CPP_SEFI_SOLDIERFACTORY_H
#define EX2_CPP_SEFI_SOLDIERFACTORY_H

#include <memory>
#include "Soldier.h"

class SoldierFactory {

    static long id;

public:

    static std::shared_ptr<Soldier>
    makeSoldier(const long id, const Point &currPosition, double hp, double speed, const short army, const short type);

    static Soldier* makeSoldier(const std::vector<std::string> &strings, const int army);

};


#endif //EX2_CPP_SEFI_SOLDIERFACTORY_H
