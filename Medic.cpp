//
// Created by damir on 16-Dec-17.
//

#include "Medic.h"

Medic::Medic(Point* currPosition, const short army)

        : Soldier(currPosition, MEDIC_HP, MEDIC_SPEED, army), fists(new Fists){}

void Medic::heal(Soldier* injured) {
    if (injured->getArmy() == _army)
        injured->healMe();
}

Medic::~Medic() {
    std::cout << "Medic dtor" << std::endl;
    delete fists;
}

void Medic::attack(Soldier *target) {

}

void Medic::whoAreYou() {
    std::cout << "I am a medic." << std::endl;
}

void Medic::pickObject(Weapon *weapon) {
    std::cout << "Medic: Cannot carry weapon" << std::endl;
}

void Medic::pickObject(BodyArmor *ba) {
    if(ba->isCarried()) return;
    std::cout << "Medic picked BodyArmor" << std::endl;
    if(_bodyarmor != nullptr) _bodyarmor->drop(this);
    _bodyarmor = ba;
    ba->setCarried(true);
    ba->setCurrentPosition(nullptr);
}

void Medic::pickObject(ShieldArmor *sa) {
    if(sa->isCarried()) return;
    if(_shield != nullptr) _shield->drop(this);
    _shield = sa;
    sa->setCarried(true);
    sa->setCurrentPosition(nullptr);
}

void Medic::healMe() {
    setHP(MEDIC_HP);
}

