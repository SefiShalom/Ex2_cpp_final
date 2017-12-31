//
// Created by damir on 25-Dec-17.
//

#ifndef EX2_CPP_SEFI_POINTSFACTORY_H
#define EX2_CPP_SEFI_POINTSFACTORY_H

#include <vector>
#include <stack>
#include "Point.h"
#include "FileTokenizer.h"

class PointsFactory {


public:

    static std::vector<Point> makePoints(std::string& input, double h, double w);

    static Point makeSinglePoint(const std::string& input);

    static int checkLineCorrectness(std::string& toCheck);
};

#endif //EX2_CPP_SEFI_POINTSFACTORY_H
