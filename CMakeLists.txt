cmake_minimum_required(VERSION 3.1)
project(CC3K)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")

set(SOURCE_FILES main.cpp)
add_executable(CC3K ${SOURCE_FILES} classes/ObjectUnit.cpp classes/ObjectUnit.h classes/Map.cpp classes/Map.h classes/Character.cpp classes/Character.h classes/characters/Human.cpp classes/characters/Human.h classes/Item.cpp classes/Item.h classes/items/Potion.cpp classes/items/Potion.h classes/ControlPanel.cpp classes/ControlPanel.h classes/Chamber.cpp classes/Chamber.h classes/MapCell.cpp classes/MapCell.h classes/characters/Dwarf.cpp classes/characters/Dwarf.h classes/characters/Elf.cpp classes/characters/Elf.h classes/characters/Orc.cpp classes/characters/Orc.h classes/characters/Vampire.cpp classes/characters/Vampire.h classes/characters/Werewolf.cpp classes/characters/Werewolf.h classes/characters/Troll.cpp classes/characters/Troll.h classes/characters/Goblin.cpp classes/characters/Goblin.h classes/characters/Merchant.cpp classes/characters/Merchant.h classes/characters/Dragon.cpp classes/characters/Dragon.h classes/characters/Phoenix.cpp classes/characters/Phoenix.h classes/items/Treasure.cpp classes/items/Treasure.h classes/items/Gold.cpp classes/items/Gold.h classes/RandomUtility.cpp classes/RandomUtility.h)
