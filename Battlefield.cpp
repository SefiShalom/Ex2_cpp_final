//
// Created by damir on 27-Dec-17.
//

#include "Battlefield.h"

Battlefield::Battlefield(double height, double width)
        : _height(height), _width(width) {}

const double Battlefield::getHeight() const {
    return _height;
}

const double Battlefield::getWidth() const {
    return _width;
}
