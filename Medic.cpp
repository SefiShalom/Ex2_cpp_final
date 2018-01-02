//
// Created by damir on 16-Dec-17.
//

#include "Medic.h"
#include "MedicStrategy.h"

Medic::Medic(const Point& position, const short army)

        : Soldier(position, MEDIC_HP, MEDIC_SPEED, army){}

void Medic::heal(Soldier* injured) {
    if (injured->getArmy() == _army)
        injured->healMe();
}

Medic::~Medic() {
    std::cout << "Medic dtor" << std::endl;
    _weapon->drop(this);
}

bool Medic::attack(Soldier *target) {
    return target->defend(_weapon);
}

void Medic::whoAreYou() {
    std::cout << "I am a medic." << std::endl;
}


void Medic::healMe() {
   refillHP(MEDIC_HP);
}


void Medic::performAction(Soldier* soldier) {
    if(getArmy() == soldier->getArmy()) {
        std::cout << *this << " healed" << *soldier << std::endl;
        soldier->healMe();
    }
    else attack(soldier);
}

void Medic::performAction(Weapon *weapon) {}

void Medic::walk() {
    Soldier::walk(MEDIC_SPEED);
}

std::ostream &Medic::toString(std::ostream &out) {
//    out<< "Medic" <<std::endl;
//    out<< "Army: " << getArmy() <<std::endl;
//    out<< "Location: " << getLocation() <<std::endl;
//    out<< "HP: " << getHP() <<std::endl;

    double x = getLocation().get_x();
    double y = getLocation().get_y();
    out << "Medic" << getArmy() << "(" << x << "," << y << ")";

    return out;
}

SoldierStrategy *Medic::getStrategy() {
    return new MedicStrategy;
}

std::string Medic::getType() {
    return "Medic";
}




