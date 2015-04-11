#include <iostream>
#include "classes/Map.h"
#include "classes/MapCell.h"
#include "classes/Character.h"
#include "classes/RandomUtility.h"

using namespace std;

int main() {
    Map& map = Map::getInstance();
    map.draw_map("map_data");
    map.update_neighbors();
    map.print_map(cout);
    map.spawn_units();
    map.print_map(cout);
    ObjectUnit* my_char = map.get_map_cell(5, 5)->object;
    my_char->move(Map::DIRECTION_E);
    map.print_map(cout);

    RandomUtility::seed();
    Character& my_actual_char = dynamic_cast<Character&>(*my_char);
    my_actual_char.attack(Map::DIRECTION_E);


}
