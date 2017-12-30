//
// Created by damir on 30-Dec-17.
//

#include <map>
#include "StatePrinter.h"

void StatePrinter::print(Game &game) {
    std::map<long, bool> hashMap;

    const std::vector<MapObject *> &map = game.getAllObjects();

    Battlefield battlefield = game.getBattlefield();

    double height = battlefield.getHeight();
    double width  = battlefield.getWidth();


    for (int k = 0; k < width; ++k) {
        std::cout << "--";
    }
    std::cout << std::endl;

    for (int i = (int)height; i >= 0; --i) {
        std::cout << "|";
        for (int j = 0; j < width; ++j) {

//            std::vector<MapObject *> around = game.retrieveObjectsWithinRadiusByPoint(Point(i,j), 1);
            MapObject *around = game.getClosestObject(Point(i,j), 1);

            if (around != nullptr && ! hashMap.find(around->getID())->second) {
//                std::cout << around->getLocation();
                std::cout << *around;
                std::pair<long, bool> p = std::make_pair<long, bool>(around->getID(), true);
                hashMap.insert( p );
            }
            else
                std::cout << "  ";
//                std::cout << "K";
//                std::cout << around;

        }
//        std::cout << "|";
        std::cout << std::endl;
    }
    for (int k = 0; k < width; ++k) {
        std::cout << "--";
    }

}
