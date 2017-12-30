//
// Created by Sefi on 12/12/2017.
//

#include "Soldier.h"
#include "Fists.h"

Soldier::Soldier(const Point &currPosition, double hp, double speed, const short army)
        : MapObject(currPosition),
          _speed(speed), _army(army),
          _bodyarmor(nullptr), _shield(nullptr), _weapon(new Fists),
          _walking(false), _hp(hp), _isAlive(true),
          _nextDestination(UNREACHABLE_POINT) {}


Soldier::~Soldier() {
//    std::cout << "Soldier dtor" << std::endl;
}


void Soldier::setNextDestination(const Point &nextPoint) {
    _nextDestination = nextPoint;
    _walking = true;
}

void Soldier::walk(double speed) {
    if (getLocation().distance(_nextDestination) <= speed) {
        setLocation(_nextDestination);
        _walking = false;
        return;
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

void Soldier::feedMeWithDestinations(std::vector<Point *> points) {
    allDestinations = std::vector<Point*>(points);
    std::cout << "I got a point vector: " << std::endl;
    for (auto &i : allDestinations) {
        std::cout << i << std::endl;
    }
}


bool Soldier::reduceHP(double hp) {
    _hp -= hp;

    if(_hp <= 0) return true;

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

    if(!(_bodyarmor || _shield)){
        damage = weapon->getPower();
    }else {
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

    std::cout << "The attack power was reduced by " << weapon->getPower() - damage << ".\n"
            "The original damage was supposed to be " << weapon->getPower() << ".\nTotal damage: " << damage
              << std::endl;

    return reduceHP(damage);

}


double Soldier::getHP() const {
    return _hp;
}

void Soldier::performAction(ShieldArmor* shield) {
    pickObject(shield);
}

void Soldier::performAction(BodyArmor* bodyarmor) {
    pickObject(bodyarmor);
}

void Soldier::performAction(SolidObject* solidObject) {
    std::cout << "SolidObject Ahead!" << std::endl;
}

std::vector<MapObject> Soldier::scanRadius() {
    return std::vector<MapObject>();
}

void Soldier::acceptAction(Soldier* soldier) {
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





