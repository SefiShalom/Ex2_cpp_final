cmake_minimum_required(VERSION 3.9)
project(Ex2_cpp_sefi)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ex2_cpp_sefi main.cpp Point.cpp Point.h Object.cpp Object.h CollectableObject.cpp CollectableObject.h Armor.cpp Armor.h SheildArmor.cpp SheildArmor.h Weapon.cpp Weapon.h SolidObject.cpp SolidObject.h Rifle.cpp Rifle.h Soldier.cpp Soldier.h BodyArmor.cpp BodyArmor.h Medic.h Medic.cpp)