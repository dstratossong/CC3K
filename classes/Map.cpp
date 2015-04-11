//
// Created by glados on 4/5/15.
//

#include "Map.h"
#include "MapCell.h"
#include "Chamber.h"
#include "characters/Human.h"
#include "characters/Vampire.h"
#include <fstream>

Map::Map() {};

Map::~Map() {
    for (int i = 1; i <= FLOOR_HEIGHT; i++) {
        for (int j = 1; j <= FLOOR_WIDTH; j++) {
            delete landscape[i][j];
        }
    }
}

void Map::draw_map(char const * map_file_name) {
    std::ifstream file(map_file_name);

    if (!file.is_open()) {
        std::cout << "ERROR" << std::endl;
        return;
    }

    // Read map_data
    std::vector<MapCell*> first_row; // first row..
    landscape.push_back(first_row);

    for (int i = 1; i <= FLOOR_HEIGHT; i++) {
        std::vector<MapCell*> row;
        std::string read_line;
        getline(file, read_line);

        row.push_back(NULL); // first column..

        for (int j = 1; j <= FLOOR_WIDTH; j++) {
            switch (read_line[j-1]) {
                case CELL_FLOOR:
                case CELL_BLANK:
                case CELL_DOORWAY:
                case CELL_PASSAGE:
                case CELL_WALL_HORIZONTAL:
                case CELL_WALL_VERTICAL:
                    MapCell* cell = new MapCell(i, j, read_line[j-1]);
                    row.push_back(cell);
                    break;
            }
        }
        landscape.push_back(row);
    }

    // Read map meta-data
    // - chambers
    for (int i = 0; i < NUMBER_OF_CHAMBERS; i++) {
        Chamber chamber;
        int number_of_cells;
        file >> number_of_cells;
        for (int j = 0; j < number_of_cells; j++) {
            int cell_pos_x, cell_pos_y;
            file >> cell_pos_x >> cell_pos_y;
            MapCell* cell = get_map_cell(cell_pos_x, cell_pos_y);
            if (cell) {
                chamber.chamber_cells.push_back(cell);
            }
        }
        chambers.push_back(chamber);
    }

    // close stream
    file.close();
}

void Map::clear_map() {

}

MapCell* Map::get_map_cell(int row, int column) {
    // check range
    if (row <= 0 || row > FLOOR_HEIGHT ||
            column <= 0 || column > FLOOR_WIDTH) {
        return NULL;
    } else {
        return landscape[row][column];
    }
}

// Only counts cells that units can move to (CELL_FLOOR)
void Map::update_neighbors() {

    for (int i = 1; i <= FLOOR_HEIGHT; i++) {
        for (int j = 1; j <= FLOOR_WIDTH; j++) {
            MapCell* this_cell = get_map_cell(i, j);
            if (this_cell->cell_type != CELL_FLOOR)
                continue;

            for (int k = 0; k < 8; k++) {
                MapCell* cell;
                switch (k) {
                    case DIRECTION_N:
                        cell = get_map_cell(i-1, j);
                        break;
                    case DIRECTION_NW:
                        cell = get_map_cell(i-1, j-1);
                        break;
                    case DIRECTION_W:
                        cell = get_map_cell(i, j-1);
                        break;
                    case DIRECTION_SW:
                        cell = get_map_cell(i+1, j-1);
                        break;
                    case DIRECTION_S:
                        cell = get_map_cell(i+1, j);
                        break;
                    case DIRECTION_SE:
                        cell = get_map_cell(i+1, j+1);
                        break;
                    case DIRECTION_E:
                        cell = get_map_cell(i, j+1);
                        break;
                    case DIRECTION_NE:
                        cell = get_map_cell(i-1, j+1);
                        break;
                }
                if (cell && cell->cell_type == CELL_FLOOR)
                    this_cell->neighbors.push_back(cell);
            }
        }
    }
}

void Map::spawn_units() {
    spawn_human(5, 5);
    spawn_vampire(5, 7);

    // Spawn stairs

    // Spawn ...
}

void Map::print_map(std::ostream& out) {
    for (int i = 1; i <= FLOOR_HEIGHT; i++) {
        for (int j = 1; j <= FLOOR_WIDTH; j++) {
            if (landscape[i][j]->object) {
                out << landscape[i][j]->object->get_display_symbol();
            } else {
                out << landscape[i][j]->cell_type;
            }
        }
        out << std::endl;
    }
}


// Spawning Implementations
MapCell* Map::get_spawning_ground(int pos_x, int pos_y) {
    MapCell* cell = get_map_cell(pos_x, pos_y);
    if (!cell || cell->cell_type != CELL_FLOOR || cell->object)
        throw 1;
    return cell;
}

void Map::spawn_human(int pos_x, int pos_y) {
    MapCell* cell = get_spawning_ground(pos_x, pos_y);
    cell->object = new Human(this, cell, pos_x, pos_y);
    units.push_back(cell->object);
}

void Map::spawn_vampire(int pos_x, int pos_y) {
    MapCell* cell = get_spawning_ground(pos_x, pos_y);
    cell->object = new Vampire(this, cell, pos_x, pos_y);
    units.push_back(cell->object);
}
