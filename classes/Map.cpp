//
// Created by glados on 4/5/15.
//

#include "Map.h"
#include <iostream>
#include <fstream>

void Map::draw_map(char* map_file_name) {
    std::ifstream file(map_file_name);

    if (!file.is_open())
        return;

    // see map_data for formatting
    for (int i = 1; i < this->FLOOR_HEIGHT; i++) {
        std::string read_line;
        getline(file, read_line);

    }
    file.close();
}

MapCell* Map::get_map_cell(int x, int y) {
    // check range
    if (x <= 0 || x > FLOOR_WIDTH ||
        y <= 0 || y > FLOOR_HEIGHT) {
        return NULL;
    } else {
        return landscape[x][y];
    }
}

