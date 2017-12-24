//
// Created by damir on 19-Dec-17.
//

#include "Fighter.h"
#include "Missile.h"

Fighter::Fighter(const Point& position, size_t hp, double speed, const int army)
        : Soldier(position, hp, speed, army), _weapon(nullptr){}

void Fighter::attack(Soldier *target) {
    target->defend(_weapon);
}

void Fighter::pickObject(BodyArmor *ba) {
    if(ba->isCarried()) return;
    if(_bodyarmor != nullptr) _bodyarmor->drop(this);
    _bodyarmor = ba;
    ba->setCarried(true);
    ba->setLocation(UNREACHABLE_POINT);
}

void Fighter::pickObject(ShieldArmor *sa) {
    if(sa->isCarried()) return;
    if(_shield != nullptr) _shield->drop(this);
    _shield = sa;
    sa->setCarried(true);
    sa->setLocation(UNREACHABLE_POINT);
}

void Fighter::pickObject(Weapon *weapon) {
    if(weapon->isCarried()) return;
    if(_weapon!= nullptr) _weapon->drop(this);
    _weapon = weapon;
    weapon->setCarried(true);
    weapon->setLocation(UNREACHABLE_POINT);
}

Fighter::~Fighter() {
    std::cout << "Fighter dtor" << std::endl;
}

void Fighter::set_weapon(Weapon* weapon) {
    _weapon = weapon;
}

//void Fighter::defend(Weapon *weapon) {
//    double damage = 1;
////    if(_bodyarmor != nullptr) damage = _bodyarmor->defend(weapon);
//    // power*defense*power*defense/power
//
//    int counter = -1;
//
//    if (_bodyarmor != nullptr){
//        damage = _bodyarmor->defend(weapon);
//        counter++;
//    }
//    if (_shield != nullptr) {
//        damage *= _shield->defend(weapon);
//        counter++;
//    }
//
//    damage /= pow(weapon->getPower(), counter != -1 ? counter : 0);
//
//    std::cout << "The attack power was reduced by " << weapon->getPower() - damage << ".\n"
//            "The original damage was supposed to be " << weapon->getPower() << ".\nTotal damage: " << damage << std::endl;
//    reduceHP(damage);
//
////    if (dynamic_cast<Missile*>(weapon)) {
////        std::cout << "YES MISSILE" << std::endl;
////        if (_shield != nullptr) {
////            damage *= _shield->getDefensePower();
////            std::cout << "YES SHIELD" << std::endl;
////        }
////    } else {
////        std::cout << "NOT MISSILE" << std::endl;
////        if (_shield != nullptr) {
////            damage *= _shield->getDefensePower();
////            std::cout << "YES SHIELD" << std::endl;
////        }
////        if (_bodyarmor != nullptr) {
////            damage *= _bodyarmor->getDefensePower();
////            std::cout << "YES BODYARMOR" << std::endl;
////        }
////    }
//
////    std::cout << "DAMAGE = " << damage << std::endl;
////    damage = std::max(0.65, damage);
////
////    reduceHP(weapon->getPower() * damage);
////
////    std::cout << "Reduced by " << weapon->getPower() * damage << " HP" << std::endl;
//}
