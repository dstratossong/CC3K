//
// Created by glados on 4/5/15.
//

#ifndef CC3K_MAP_H
#define CC3K_MAP_H


#include "ObjectUnit.h"
#include "MapCell.h"
#include "Chamber.h"

class Map {
public:
    // public fields

    // public methods
    void draw_map(char* map_file_name); // Reads in map data, found in the file name

private:
    // private fields
    const int FLOOR_WIDTH = 79;
    const int FLOOR_HEIGHT = 25;

    const int NUMBER_OF_FLOORS = 5;
    const int NUMBER_OF_CHAMBERS = 5;

    const char CELL_BLANK = ' ';
    const char CELL_WALL_HORIZONTAL = '-';
    const char CELL_WALL_VERTICAL = '|';
    const char CELL_FLOOR = '.'; // note: representation is unoccupied, though not necessarily the case
    const char CELL_DOORWAY = '+';
    const char CELL_PASSAGE = '#';

    MapCell*** landscape; // 2D array of MapCell pointers
    ObjectUnit** object_units; // 1D array of ObjectUnit pointers
    Chamber** chambers; // 1D array of Chamber pointers

    // private methods
    MapCell* get_map_cell(int x, int y);

    void update_neighbors();
    void spawn_units();
    void move_randomly();
    void print_map();
};


#endif //CC3K_MAP_H
