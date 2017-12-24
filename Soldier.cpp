//
// Created by Sefi on 12/12/2017.
//

#include "Soldier.h"

#define OUT_OF_RANGE -10


Soldier::Soldier(Point *currPosition, double hp, double speed, const short army)
        : MapObject(currPosition),
          _speed(speed), _army(army), _nextDestination(nullptr),
          _bodyarmor(nullptr),_shield(nullptr),_weapon(nullptr),
          _walking(false), _hp(hp) {}


Soldier::~Soldier() {
    std::cout << "Soldier dtor" << std::endl;
    if(_nextDestination != nullptr) delete _nextDestination;
    if(_bodyarmor != nullptr) delete _bodyarmor;
    if( _shield != nullptr) delete _shield;
    if( _weapon != nullptr) delete _weapon;
}


void Soldier::setNextDestination(Point* nextPoint) {
    if(_nextDestination != nullptr) delete _nextDestination;
    _nextDestination = nextPoint;
    _walking = true;
}

void Soldier::walk() {

    if(_nextDestination == nullptr) return;

    if(getPosition()->distance(*_nextDestination) <= _speed) {
            setCurrentPosition(_nextDestination);
            delete _nextDestination;
            _walking = false;
            return;
        }
    Point* nextPoint = new Point(getPosition()->nextPoint(_speed,*_nextDestination));
    setCurrentPosition(nextPoint);
    }

bool Soldier::isWalking() {
    return _walking;
}


const int Soldier::getArmy() const {
    return _army;
}

void Soldier::feedMeWithDestinations(std::vector<Point*> points) {
    allDestinations = std::vector<Point*>(points);
    std::cout << "I got a point vector: " << std::endl;
    for (auto& i : allDestinations) {
        std::cout << i << std::endl;
    }
}
std::ostream& operator<<(std::ostream& os, const Soldier& soldier) {
    os << "Printing Soldier info: " << std::endl;
    os << "Army: " << soldier._army << std::endl;
    os << "HP: " << soldier._hp << std::endl;
    os << "Current position: " << *(soldier.getPosition()) << std::endl;
//    os << "All points: " << std::endl;
//    size_t currpoint = 1;
//    for (auto& point : soldier.allDestinations) {
//        os << "Point number " << currpoint << ": " << point << std::endl;
//        currpoint++;
//    }
}

void Soldier::setCurrentPosition(Point *newPoint) {
    if(_position != nullptr) delete _position;
    _position = newPoint;
}

void Soldier::reduceHP(double hp) {
    _hp -= hp;
}

void Soldier::set_bodyarmor(BodyArmor* bodyarmor) {
    _bodyarmor = bodyarmor;
}

void Soldier::set_shield(ShieldArmor* shield) {
    _shield = shield;
}

void Soldier::defend(Weapon* weapon){}

void Soldier::refillHP(double refill) {
    _hp = refill;
}






//void Soldier::dropCollectable(CollectableObject* col) {
//    if (col != nullptr) {
//        col->setCurrentPosition(*_currPosition);
//        col->setCarried(false);
//    }
//}


