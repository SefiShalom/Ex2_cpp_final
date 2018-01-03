//
// Created by damir on 25-Dec-17.
//

#ifndef EX2_CPP_SEFI_POINTSFACTORY_H
#define EX2_CPP_SEFI_POINTSFACTORY_H

#include <vector>
#include <stack>
#include "Point.h"
#include "FileTokenizer.h"

/**
 *  This class generates point or points by given string input
 */
class PointsFactory {

    //  Checks the line correctness of the given input
    //  This function checks, using a stack, the balance of the square brackets [] and the number of points accordingly
    static int checkLineCorrectness(std::string &toCheck);

public:

    //  Creates the point vector for the HumanPlayer
    static std::vector<Point> makePoints(std::string &input, double h, double w);

    //  Creates a single point, mainly for parsing the game CSV init file
    static Point makeSinglePoint(const std::string &input);
};

#endif //EX2_CPP_SEFI_POINTSFACTORY_H
