//
// Created by damir on 25-Dec-17.
//

#include "PointsFactory.h"


std::vector<Point> PointsFactory::makePoints(std::string& input) {
    std::vector<Point> ret;

    int checkCorrectness = checkLineCorrectness(input);

    if (checkCorrectness == -1) {
        std::cout << "ERROR IN POINT FACTORY" << std::endl;
    }

    FileTokenizer ft(input);
    std::vector<std::string> strings = ft.tokenizeBy("[], \r");
    std::vector<double> nums;
    for (auto &i : strings) {
        nums.emplace_back(std::stod(i));
    }

    for (int i = 0; i < nums.size(); ++i) {
        double left = nums[i++];
        if (i == nums.size()) {
            std::cout << "\t\t\t\tERROR IN POINT FACTORY!!!" << std::endl;
        }
        double right = nums[i];

        ret.emplace_back(Point(left, right));

    }


    if (checkCorrectness != ret.size()) {
        std::cout << "ERROR IN POINT FACTORY!" << std::endl;
    }

    return ret;
}


int PointsFactory::checkLineCorrectness(std::string& toCheck) {

    std::stack<char> chars;

    int points = 0;

    for (int i = 0; i < toCheck.size(); ++i) {
        if (toCheck[i] == '[') {
            chars.push('[');
            points++;
        }
        else if (toCheck[i] == ']') {
            if (chars.empty()) {
                std::cout << "Unbalanced point string" << std::endl;
                return -1;
            }
            chars.pop();
        }
    }

    if (! chars.empty()) {
        std::cout << "Unbalanced point string" << std::endl;
        return -1;
    }

    return points;
}

Point PointsFactory::makeSinglePoint(const std::string &input) {
    if (input.empty()) {
        std::cerr << "Wrong input at single point factory!" << std::endl;
    }
    FileTokenizer ft(input);
    std::vector<std::string> strings = ft.tokenizeBy("[], ");
    if (strings.size() != 2) {
        std::cout << "ERROR IN SINGLE POINT FACTORY!" << std::endl;
        return Point();
    }
    return Point(std::stoi(strings[0]), std::stoi(strings[1]));
}
