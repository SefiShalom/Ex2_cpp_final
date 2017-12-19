//
// Created by Sefi on 12/12/2017.
//

#include "Soldier.h"


Soldier::Soldier(const Point &currPosition, size_t hp, double speed, const int army)
        : _currPosition(new Point(currPosition)), _hp(hp), _speed(speed), _army(army), _nextDestination(nullptr), _walking(false), _init_hp(hp) {


}


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

void Soldier::healMe() {
    _hp = _init_hp;
}

const int Soldier::getArmy() const {
    return _army;
}

void Soldier::feedMeWithDestinations(std::vector<Point> points) {
    allDestinations = std::vector<Point>(points);
    std::cout << "I got a point vector: " << std::endl;
    for (auto& i : allDestinations) {
        std::cout << i << std::endl;
    }
}
std::ostream& operator<<(std::ostream& os, const Soldier& soldier) {
    os << "Printing Soldier info: " << std::endl;
    os << "Army: " << soldier._army << std::endl;
    os << "HP: " << soldier._hp << std::endl;
    os << "Current position: " << *soldier._currPosition << std::endl;
//    os << "All points: " << std::endl;
//    size_t currpoint = 1;
//    for (auto& point : soldier.allDestinations) {
//        os << "Point number " << currpoint << ": " << point << std::endl;
//        currpoint++;
//    }
}


void Soldier::pickObject(CollectableObject *object) {
//    object->useObject(this);
}

void Soldier::setCollectable(BodyArmor *ba) {

}

void Soldier::setCollectable(ShieldArmor *sa) {

}

void Soldier::setCollectable(Weapon *weapon) {

}

void Soldier::dropCollectable(CollectableObject* col) {
    
}


