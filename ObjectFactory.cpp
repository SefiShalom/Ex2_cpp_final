//
// Created by damir on 30-Dec-17.
//

#include "ObjectFactory.h"
#include "PointsFactory.h"
#include "M16.h"
#include "Uzi.h"
#include "Missile.h"

Weapon *ObjectFactory::makeWeapon(const std::vector<std::string> &info) {

    std::string type = info[1];
    const Point point = PointsFactory::makeSinglePoint(info[2]);

    if (type == "M16") {
        return new M16(point);
    }
    else if (type == "UZI") {
        return new Uzi(point);
    }
    else if (type == "Missile") {
        return new Missile(point);
    }
    else {
        return nullptr;
    }

}

Armor *ObjectFactory::makeArmor(const std::vector<std::string> &info) {
    std::string type    = info[1];
    double defensePower = std::stod(info[2]);
    const Point point   = PointsFactory::makeSinglePoint(info[3]);

    if (type == "BodyArmor") {
        return new BodyArmor(point, defensePower);
    }
    else if (type == "ShieldArmor") {
        return new ShieldArmor(point, defensePower);
    }
    else {
        return nullptr;
    }

}

SolidObject *ObjectFactory::makeSolidObject(const std::vector<std::string> &info) {
    if (info.size() < 5) {
        return nullptr;
    }
    std::string type  = info[1];
    const Point point = PointsFactory::makeSinglePoint(info[4]);
    double height     = std::stod(info[2]);
    double width      = std::stod(info[3]);

    return new SolidObject(point, height, width);

}
