//
// Created by damir on 16-Dec-17.
//

#include "Medic.h"

Medic::Medic(const Point &currPosition, size_t hp, double speed, const int army)
        : Soldier(currPosition, hp, speed, army) {

}

void Medic::heal(Soldier* injured) {
    if (injured->getArmy() == _army)
        injured->healMe();
}


void Medic::attack(Soldier *target) {

}

void Medic::pickObject(CollectableObject *object) {

}

void Medic::dropObject(Point position) {
    // TODO
}

void Medic::defend(Weapon* weapon) {
//    double reduce = _shield->defend(weapon);
//    std::cout << "Medic had HP: " << _hp << ", but he was attacked so now he has HP: " << _hp-reduce << std::endl;
//    _hp -= reduce;
//    double reducer = 0;
//    if (_bodyarmor != nullptr)
//        reducer += weapon->attackArmor(_bodyarmor);
//    if (_shield != nullptr)
//        reducer += weapon->attackArmor(_shield);
}

const Point Medic::getCurrentPosition() {
    return Point(*_currPosition);
}

void Medic::whoAreYou() {
    std::cout << "I am a medic." << std::endl;
}

void Medic::pickObject(Weapon *weapon) {
    std::cout << "Cannot carry weapon \n Medics can only use their hands! " << std::endl;
}

void Medic::pickObject(BodyArmor *ba) {
    std::cout << "Medic picked BodyArmor" << std::endl;
    if(_bodyarmor != nullptr) _bodyarmor->drop(_currPosition);
    _bodyarmor = ba;
    ba->setCarried(true);
    ba->setCurrentPosition(new Point(OUT_OF_RANGE,OUT_OF_RANGE));
}

void Medic::pickObject(ShieldArmor *sa) {
    std::cout << "Medic picked ShieldArmor" << std::endl;
    std::cout << (_shield == nullptr) << std::endl;

    if(_shield != nullptr) _shield->drop(_currPosition);
    _shield = sa;
    sa->setCarried(true);
    sa->setCurrentPosition(new Point(OUT_OF_RANGE,OUT_OF_RANGE));
}
