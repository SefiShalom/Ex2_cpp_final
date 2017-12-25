//
// Created by Sefi on 12/12/2017.
//

#include "Soldier.h"


Soldier::Soldier(const Point& currPosition, double hp, double speed, const short army)
        : MapObject(currPosition),
          _speed(speed), _army(army),
          _bodyarmor(nullptr),_shield(nullptr),
          _walking(false), _hp(hp), _nextDestination(UNREACHABLE_POINT) {}


Soldier::~Soldier() {
//    std::cout << "Soldier dtor" << std::endl;
}


void Soldier::setNextDestination(const Point& nextPoint) {
    _nextDestination = nextPoint;
    _walking = true;
}

void Soldier::walk(double speed) {

    if(getLocation().distance(_nextDestination) <= speed) {
            setLocation(_nextDestination);
            _walking = false;
            return;
        }
    Point nextPoint = getLocation().nextPoint(speed,_nextDestination);
    setLocation(nextPoint);
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
    os << "Current position: " << soldier.getLocation() << std::endl;
//    os << "All points: " << std::endl;
//    size_t currpoint = 1;
//    for (auto& point : soldier.allDestinations) {
//        os << "Point number " << currpoint << ": " << point << std::endl;
//        currpoint++;
//    }
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

//void Soldier::defend(Weapon* weapon){
//
//
//
//}

void Soldier::refillHP(double refill) {
    _hp = refill;
}

void Soldier::defend(Weapon *weapon) {
    double damage = 1;
//    if(_bodyarmor != nullptr) damage = _bodyarmor->defend(weapon);
    // power*defense*power*defense/power

    int counter = -1;

    if (_bodyarmor != nullptr){
        damage = _bodyarmor->defend(weapon);
        counter++;
    }
    if (_shield != nullptr) {
        damage *= _shield->defend(weapon);
        counter++;
    }

    damage /= pow(weapon->getPower(), counter != -1 ? counter : 0);

    std::cout << "The attack power was reduced by " << weapon->getPower() - damage << ".\n"
            "The original damage was supposed to be " << weapon->getPower() << ".\nTotal damage: " << damage << std::endl;
    reduceHP(damage);
}


void Soldier::defend(std::shared_ptr<Weapon> weapon) {
    double damage = 1;
//    if(_bodyarmor != nullptr) damage = _bodyarmor->defend(weapon);
    // power*defense*power*defense/power

    int counter = -1;

    if (_bodyarmor != nullptr){
        damage = _bodyarmor->defend(weapon);
        counter++;
    }
    if (_shield != nullptr) {
        damage *= _shield->defend(weapon);
        counter++;
    }

    damage /= pow(weapon->getPower(), counter != -1 ? counter : 0);

    std::cout << "The attack power was reduced by " << weapon->getPower() - damage << ".\n"
            "The original damage was supposed to be " << weapon->getPower() << ".\nTotal damage: " << damage << std::endl;
    reduceHP(damage);
}






double Soldier::getHP() const {
    return _hp;
}






//void Soldier::dropCollectable(CollectableObject* col) {
//    if (col != nullptr) {
//        col->setCurrentPosition(*_currPosition);
//        col->setCarried(false);
//    }
//}


