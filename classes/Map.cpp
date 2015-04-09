//
// Created by glados on 4/5/15.
//

#include "Map.h"
#include "MapCell.h"
#include "Chamber.h"
#include <fstream>

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
    const int N = 0;
    const int NE = 1;
    const int E = 2;
    const int SE = 3;
    const int S = 4;
    const int SW = 5;
    const int W = 6;
    const int NW = 7;

    for (int i = 1; i <= FLOOR_HEIGHT; i++) {
        for (int j = 1; j <= FLOOR_WIDTH; j++) {
            MapCell* this_cell = get_map_cell(i, j);
            if (this_cell->cell_type != CELL_FLOOR)
                continue;

            for (int k = 0; k < 8; k++) {
                MapCell* cell;
                switch (k) {
                    case N:
                        cell = get_map_cell(i-1, j);
                        break;
                    case NW:
                        cell = get_map_cell(i-1, j-1);
                        break;
                    case W:
                        cell = get_map_cell(i, j-1);
                        break;
                    case SW:
                        cell = get_map_cell(i+1, j-1);
                        break;
                    case S:
                        cell = get_map_cell(i+1, j);
                        break;
                    case SE:
                        cell = get_map_cell(i+1, j+1);
                        break;
                    case E:
                        cell = get_map_cell(i, j+1);
                        break;
                    case NE:
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
    // Spawn player pos = (5, 5)


    // Spawn stairs

    // Spawn ...
}


void Map::print_map(std::ostream& out) {
    for (int i = 1; i <= FLOOR_HEIGHT; i++) {
        for (int j = 1; j <= FLOOR_WIDTH; j++) {
            if (landscape[i][j]->object) {
                out << landscape[i][j]->object->display_symbol;
            } else {
                out << landscape[i][j]->cell_type;
            }
        }
        out << std::endl;
    }
}

Map::Map() {

}

Map::~Map() {
    for (int i = 1; i <= FLOOR_HEIGHT; i++) {
        for (int j = 1; j <= FLOOR_WIDTH; j++) {
            delete landscape[i][j];
        }
    }
}