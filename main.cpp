#include <iostream>
#include "classes/Map.h"
#include "classes/MapCell.h"

using namespace std;

int main() {
    Map& map = Map::getInstance();
    map.draw_map("map_data");
    map.update_neighbors();
    map.print_map(cout);
    map.spawn_units();
    map.print_map(cout);
    ObjectUnit* my_char = map.get_map_cell(5, 5)->object;
    my_char->move(5, 6);
    map.print_map(cout);
}
