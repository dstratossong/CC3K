cmake_minimum_required(VERSION 3.1)
project(CC3K)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++03")

set(SOURCE_FILES main.cpp)
add_executable(CC3K ${SOURCE_FILES} classes/ObjectUnit.cpp classes/ObjectUnit.h classes/Map.cpp classes/Map.h classes/Character.cpp classes/Character.h classes/characters/Human.cpp classes/characters/Human.h classes/Item.cpp classes/Item.h classes/items/Potion.cpp classes/items/Potion.h classes/ControlPanel.cpp classes/ControlPanel.h classes/Chamber.cpp classes/Chamber.h classes/MapCell.cpp classes/MapCell.h)