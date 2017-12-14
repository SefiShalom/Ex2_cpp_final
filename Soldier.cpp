//
// Created by Sefi on 12/12/2017.
//

#include "Soldier.h"


Soldier::Soldier(const Point &currPosition, size_t hp, double speed, const int army)
        : _currPosition(new Point(currPosition)), _hp(hp), _speed(speed), _army(army), _nextDestination(nullptr), _walking(false) {}


Soldier::~Soldier() {
    delete _currPosition;
}

void Soldier::setCurrentPosition(double x, double y) {
    _currPosition->set_x(x);
    _currPosition->set_y(y);
}

void Soldier::nextDestination(const Point &nextPoint) {
    if(_nextDestination != nullptr) delete _nextDestination;
    _nextDestination = new Point(nextPoint);
    _walking = true;
}

void Soldier::walk() {
    if(!(*_currPosition == *_nextDestination)){
        if(_currPosition->distance(*_nextDestination) <= _speed) {
            delete _nextDestination;
            _walking = false;
        }
    }

//    setCurrentPosition()
}

bool Soldier::isWalking() {
    return _walking;
}



