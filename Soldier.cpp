//
// Created by Sefi on 12/12/2017.
//

#include "Soldier.h"
#include "Game.h"
#include "Fists.h"

Soldier::Soldier(const Point &currPosition, double hp, double speed, const short army)
        : MapObject(currPosition),
          _speed(speed), _army(army),
          _bodyarmor(nullptr), _shield(nullptr), _weapon(new Fists),
          _walking(false), _hp(hp), _isAlive(true),_isBypassingSolidObject(false),
          _nextDestination(UNREACHABLE_POINT), currDestinationIndex(0) {}


Soldier::~Soldier() {
//    std::cout << "Soldier dtor" << std::endl;
}


void Soldier::setNextDestination(const Point &nextPoint) {
    _nextDestination = nextPoint;
    _walking = true;
}

void Soldier::walk(double speed) {
    _walking = true;
    if (getLocation().distance(_nextDestination) <= speed) {
        setLocation(_nextDestination);
        _isBypassingSolidObject = false;
        if (!loadNextDest()) {
//            _walking = false;
//            _isBypassingSolidObject = false;
            return;
        }
    }

    Point nextPoint = getLocation().nextPoint(speed, _nextDestination);
    setLocation(nextPoint);
}

bool Soldier::isWalking() {
    return _walking;
}


const int Soldier::getArmy() const {
    return _army;
}

void Soldier::feedMeWithDestinations(std::vector<Point> points) {
    allDestinations = std::vector<Point>(points);
//    std::cout << "I got a point vector: " << std::endl;
//    for (auto &i : allDestinations) {
//        std::cout << i << std::endl;
//    }
    setNextDestination(allDestinations[currDestinationIndex]);
}


bool Soldier::reduceHP(double hp) {
    _hp -= hp;

    if (_hp <= 0){
        _hp = 0;
        return true;
    }

    return false;
}

void Soldier::set_bodyarmor(BodyArmor *bodyarmor) {
    _bodyarmor = bodyarmor;
}

void Soldier::set_shield(ShieldArmor *shield) {
    _shield = shield;
}


void Soldier::refillHP(double refill) {
    _hp = refill;
}


bool Soldier::defend(Weapon *weapon) {

    double damage = 1;

    int counter = -1;

    if (!(_bodyarmor || _shield)) {
        damage = weapon->getPower();
    } else {
        if (_bodyarmor) {
            damage = _bodyarmor->defend(weapon);
            counter++;
        }
        if (_shield) {
            damage *= _shield->defend(weapon);
            counter++;
        }
    }

    damage /= pow(weapon->getPower(), counter != -1 ? counter : 0);

//    std::cout << "The attack power was reduced by " << weapon->getPower() - damage << ".\n"
//            "The original damage was supposed to be " << weapon->getPower() << ".\nTotal damage: " << damage
//              << std::endl;

    return reduceHP(damage);

}


double Soldier::getHP() const {
    return _hp;
}

void Soldier::performAction(ShieldArmor *shield) {
    pickObject(shield);
}

void Soldier::performAction(BodyArmor *bodyarmor) {
    pickObject(bodyarmor);
}

void Soldier::performAction(SolidObject *solidObject) {
    if(solidObject->isPointInside(getLocation().nextPoint(_speed,_nextDestination))){

    }
}

void Soldier::acceptAction(Soldier *soldier) {
    soldier->performAction(this);
}

void Soldier::pickObject(BodyArmor *ba) {
    if (ba->isCarried()) return;

    if (_bodyarmor != nullptr) {
        _bodyarmor->drop(this);
        set_bodyarmor(nullptr);
    }
    set_bodyarmor(ba);
    ba->setCarried(true);
    ba->setLocation(UNREACHABLE_POINT);
}

void Soldier::pickObject(ShieldArmor *sa) {
    if (sa->isCarried()) return;
    if (_shield != nullptr) {
        _shield->drop(this);
        set_shield(nullptr);
    }
    set_shield(sa);
    sa->setCarried(true);
    sa->setLocation(UNREACHABLE_POINT);
}

bool Soldier::isAlive() {
    return _isAlive;
}

Weapon *Soldier::get_weapon() const {
    return _weapon;
}

BodyArmor *Soldier::get_bodyarmor() const {
    return _bodyarmor;
}

ShieldArmor *Soldier::get_shield() const {
    return _shield;
}

bool Soldier::loadNextDest() {

    if (currDestinationIndex >= allDestinations.size()) {
        _walking = false;
        return false;
    }

    _nextDestination = allDestinations[currDestinationIndex];
    if(!isBypassingSolidObject()) currDestinationIndex++;

    _walking = true;
    return true;
}

std::ostream &Soldier::info(std::ostream &os) {
    os << "Soldier: " << *this << std::endl;
    os << "ID: " << getID() << std::endl;
    os << "HP: " << _hp << std::endl;
    if (_weapon)os << "Weapon: " << *_weapon << std::endl;
    if (_shield) os << "Shield: " << *_shield << std::endl;
    if (_bodyarmor) os << "BodyArmor: " << *_bodyarmor << std::endl;
    return os;
}

std::vector<SolidObject *> Soldier::retrieveSolidObjectsInRadius(Game* game) {
    std::vector<SolidObject *> objects;
    SolidObject* solid;
//    for(auto & it : game->_gameMap)
//        if(solid = dynamic_cast<SolidObject*>(it) ) objects.emplace_back(solid);
    return objects;
}

void Soldier::setIsBypassingSolidObject(bool is) {
    _isBypassingSolidObject  = is;
}

bool Soldier::isBypassingSolidObject() {
    return _isBypassingSolidObject;
}






