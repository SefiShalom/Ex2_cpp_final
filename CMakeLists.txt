cmake_minimum_required(VERSION 3.8.2)

project(Ex2_cpp_sefi)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ex2_cpp_sefi main.cpp Point.cpp Point.h Soldier.cpp Soldier.h MapObject.cpp MapObject.h CollectableObject.cpp CollectableObject.h Armor.cpp Armor.h ShieldArmor.cpp ShieldArmor.h Weapon.cpp Weapon.h SolidObject.cpp SolidObject.h Rifle.cpp Rifle.h BodyArmor.cpp BodyArmor.h Medic.h Medic.cpp Player.cpp Player.h Missile.cpp Missile.h Fighter.cpp Fighter.h Fists.cpp Fists.h M16.cpp M16.h RegularSoldier.cpp RegularSoldier.h SniperSoldier.cpp SniperSoldier.h FileReader.cpp FileReader.h FileTokenizer.cpp FileTokenizer.h PointsFactory.cpp PointsFactory.h Uzi.cpp Uzi.h SoldierFactory.cpp SoldierFactory.h HumanPlayer.cpp HumanPlayer.h Game.cpp Game.h SoldierStrategy.cpp SoldierStrategy.h MedicStrategy.cpp MedicStrategy.h FileParser.cpp FileParser.h GameFileParser.cpp GameFileParser.h Battlefield.cpp Battlefield.h ComputerPlayer.cpp ComputerPlayer.h ObjectFactory.cpp ObjectFactory.h Building.cpp Building.h)

