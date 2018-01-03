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

    //Creats a Soldier instance by parsing a given string
    //Check correctness of the input
    static Soldier* makeSoldier(const std::vector<std::string> &strings, const int army);

};


#endif //EX2_CPP_SEFI_SOLDIERFACTORY_H
