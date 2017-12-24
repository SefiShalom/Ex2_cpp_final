cmake_minimum_required(VERSION 3.8.2)

project(Ex2_cpp_sefi)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ex2_cpp_sefi main.cpp Point.cpp Point.h Soldier.cpp Soldier.h MapObject.cpp MapObject.h CollectableObject.cpp CollectableObject.h Armor.cpp Armor.h ShieldArmor.cpp ShieldArmor.h Weapon.cpp Weapon.h SolidObject.cpp SolidObject.h Rifle.cpp Rifle.h BodyArmor.cpp BodyArmor.h Medic.h Medic.cpp Player.cpp Player.h Missile.cpp Missile.h Fighter.cpp Fighter.h Fists.cpp Fists.h M16.cpp M16.h RegularSoldier.cpp RegularSoldier.h SniperSoldier.cpp SniperSoldier.h)