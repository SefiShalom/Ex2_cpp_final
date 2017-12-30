//
// Created by damir on 30-Dec-17.
//

#include <map>
#include "StatePrinter.h"

void StatePrinter::print(Game &game) {
//    std::map<MapObject, bool> hashMap;

    const std::vector<MapObject *> &map = game.getAllObjects();

    Battlefield battlefield = game.getBattlefield();

    double height = battlefield.getHeight();
    double width  = battlefield.getWidth();

    for (int i = 0; i < height; ++i) {

        for (int j = 0; j < width; ++j) {

//            std::vector<MapObject *> around = game.retrieveObjectsWithinRadiusByPoint(Point(i,j), 1);
            MapObject *around = game.getClosestObject(Point(i,j), 1);
//            hashMap.insert(around, true);
            if (around != nullptr)
                std::cout << around->getLocation();
//                std::cout << "K";
//                std::cout << around;
            else
                std::cout << "  ";

        }

        std::cout << std::endl;

    }

}
