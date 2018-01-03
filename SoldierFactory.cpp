//
// Created by damir on 26-Dec-17.
//

#include "SoldierFactory.h"
#include "RegularSoldier.h"
#include "SniperSoldier.h"
#include "Medic.h"
#include "PointsFactory.h"
#include "M16.h"
#include "Missile.h"
#include "Uzi.h"

#define REGULAR_SOLDIER 1
#define SNIPER_SOLDIER 2
#define MEDIC_SOLDIER 3

long SoldierFactory::id = 1;



Soldier *SoldierFactory::makeSoldier(const std::vector<std::string> &strings, const int army) {

    if (strings.size() < 2) {
        return nullptr;
    }

    std::string type      = strings[0];
    std::string pointStr  = strings[1];

    if (type != "paramedic" && strings.size() < 3) {
        return nullptr;
    }

    RegularSoldier *reg;
    SniperSoldier *sniper;
    Medic *medic;

    bool isRegular = false;
    bool isSniper = false;
    bool isMedic = false;

    Weapon *weapon;

    Point point = PointsFactory::makeSinglePoint(pointStr);


    if (type == "normal") {
        reg = new RegularSoldier(point, army);
        isRegular = true;
    }
    else if (type == "sniper") {
        sniper = new SniperSoldier(point, army);
        isSniper = true;
    }
    else if (type == "paramedic") {
        medic = new Medic(point, army);
        isMedic = true;
    }
    else {
        std::cerr << "Error in SoldierFactory! GOT TYPE = " << type << std::endl;
        return nullptr;
    }

    if (isMedic) {
        return medic;
    }

    std::string weaponStr    = strings[2];

    if (weaponStr == "M16") {
        weapon = new M16(point);
    }
    else if (weaponStr == "Missile") {
        weapon = new Missile(point);
    }
    else if (weaponStr == "UZI") {
        weapon = new Uzi(point);
    }
    else {

        if (isRegular)
            delete(reg);

        if (isSniper)
            delete(sniper);

        std::cerr << "Error in SoldierFactory! Got invalid weapon: " << weaponStr << std::endl;
        return nullptr;
    }

    if (isRegular) {
        reg->pickObject(weapon);
        return reg;
    }

    if (isSniper) {
        sniper->pickObject(weapon);
        return sniper;
    }


}
