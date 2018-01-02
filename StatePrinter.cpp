//
// Created by damir on 30-Dec-17.
//

#include <map>
#include "StatePrinter.h"

void StatePrinter::print(Game &game) {

    if (!game.isReadyToGo()) {
        return;
    }
    std::map<long, bool> hashMap;

    const std::vector<MapObject *> &map = game.getAllObjects();

    Battlefield battlefield = game.getBattlefield();

    double height = battlefield.getHeight();
    double width  = battlefield.getWidth();

    std::vector<SolidObject*> solids = game.retrieveSolidObjects();

    for (int k = 0; k < width; ++k) {
        std::cout << "--";
    }
    std::cout << std::endl;

    for (int i = (int)height; i >= 0; --i) {
        std::cout << "|";
        for (int j = 0; j < width; ++j) {

            MapObject *around = game.getClosestObject(Point(j,i), 1);

            if (around != nullptr && ! hashMap.find(around->getID())->second) {

                std::cout << *around;
                std::pair<long, bool> p = std::make_pair<long, bool>(around->getID(), true);
                hashMap.insert( p );
            }
            else {
                bool foundInside = false;
                for(auto& it : solids){

                    Point toCheck(j,i);
                    if(it->isPointInside(toCheck)) {
                        std::cout << "**";
                        foundInside = true;
                        break;
                    }
                }
                if (!foundInside) {
                    std::cout << "  ";
                }
            }

        }
        std::cout << std::endl;
    }
    for (int k = 0; k < width; ++k) {
        std::cout << "--";
    }
    std::cout << std::endl;

}
