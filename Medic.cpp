//
// Created by damir on 16-Dec-17.
//

#include "Medic.h"

Medic::Medic(const Point& position, const short army)

        : Soldier(position, MEDIC_HP, MEDIC_SPEED, army), fists(new Fists){}

void Medic::heal(Soldier* injured) {
    if (injured->getArmy() == _army)
        injured->healMe();
}

Medic::~Medic() {
    std::cout << "Medic dtor" << std::endl;
    delete fists;
}

void Medic::attack(Soldier *target) {
    // TODO
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
    ba->setLocation(Point(OUT_OF_RANGE,OUT_OF_RANGE));
}

void Medic::pickObject(ShieldArmor *sa) {
    if(sa->isCarried()) return;
    if(_shield != nullptr) _shield->drop(this);
    _shield = sa;
    sa->setCarried(true);
    sa->setLocation(UNREACHABLE_POINT);
}

void Medic::healMe() {
//    setHP(MEDIC_HP);
}

void Medic::heal(std::shared_ptr<Soldier> injured) {
    if (injured->getArmy() == _army)
        injured->healMe();
}

void Medic::attack(std::shared_ptr<Soldier> target) {

}

void Medic::pickObject(std::shared_ptr<BodyArmor> ba) {
    if(ba->isCarried())
        return;

    std::cout << "Medic picked BodyArmor" << std::endl;

    if(__bodyarmor)
        __bodyarmor->drop(this);

    __bodyarmor = ba;
    ba->setCarried(true);
    ba->setLocation(Point(OUT_OF_RANGE,OUT_OF_RANGE));
}

void Medic::pickObject(std::shared_ptr<Weapon> weapon) {
    std::cout << "Medic: Cannot carry weapon" << std::endl;
}

void Medic::pickObject(std::shared_ptr<ShieldArmor> sa) {
    if(sa->isCarried())
        return;

    std::cout << "Medic picked ShieldArmor" << std::endl;
    if(__shield)
        __shield->drop(this);

    __shield = sa;
    sa->setCarried(true);
    sa->setLocation(Point(OUT_OF_RANGE,OUT_OF_RANGE));
}

