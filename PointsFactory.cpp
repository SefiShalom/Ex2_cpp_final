//
// Created by damir on 25-Dec-17.
//

#include "PointsFactory.h"


std::vector<Point> PointsFactory::makePoints(std::string& input, double h, double w) {
    std::vector<Point> ret;

    int checkCorrectness = checkLineCorrectness(input);

    if (checkCorrectness == -1) {
        std::cerr << "Error in PointFactory" << std::endl;
    }

    FileTokenizer ft(input);
    std::vector<std::string> strings = ft.tokenizeBy("[], \r");
    std::vector<double> nums;
    for (auto &i : strings) {
        nums.emplace_back(std::stod(i));
    }

    for (int i = 0; i < nums.size(); ++i) {
        double left = nums[i++];
        if(left > w ) left = w;
        else if(left < 0) left = 0;
        if (i == nums.size()) {
            std::cout << "Error in PointFactory!" << std::endl;
        }
        double right = nums[i];
        if(right > h ) right = h;
        else if(right < 0) right = 0;
        ret.emplace_back(Point(left, right));

    }


    if (checkCorrectness != ret.size()) {
        std::cout << "Error in PointFactory!" << std::endl;
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
                std::cerr << "Unbalanced point string" << std::endl;
                return -1;
            }
            chars.pop();
        }
    }

    if (! chars.empty()) {
        std::cerr << "Unbalanced point string" << std::endl;
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
        std::cout << "Error in single PointFactory!" << std::endl;
        return Point();
    }
    return Point(std::stoi(strings[0]), std::stoi(strings[1]));
}
