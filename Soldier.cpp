//
// Created by Sefi on 12/12/2017.
//

#include "Soldier.h"


Soldier::Soldier(const Point &currPosition, size_t hp, double speed, const int army)
        : _currPosition(new Point(currPosition)), _hp(hp), _speed(speed), _army(army), _nextDestination(nullptr), _walking(false) {}


Soldier::~Soldier() {
    delete _currPosition;
}

void Soldier::setCurrentPosition(Point& newPoint) {
    if(_currPosition != nullptr) delete _currPosition;
    _currPosition = new Point(newPoint);

}

void Soldier::setNextDestination(const Point &nextPoint) {
    if(_nextDestination != nullptr) delete _nextDestination;
    _nextDestination = new Point(nextPoint);
    _walking = true;
}

void Soldier::walk() {

    if(_nextDestination == nullptr) return;

    if(_currPosition->distance(*_nextDestination) <= _speed) {
            setCurrentPosition(*_nextDestination);
            delete _nextDestination;
            _walking = false;
            return;
        }
    Point nextPoint(_currPosition->nextPoint(_speed,*_nextDestination));
    setCurrentPosition(nextPoint);
    }

bool Soldier::isWalking() {
    return _walking;
}



