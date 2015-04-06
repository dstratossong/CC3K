#include <iostream>
#include "classes/Map.h"

using namespace std;

int main() {
    Map& map = Map::getInstance();
    map.draw_map("map_data");
    map.print_map(cout);
}
