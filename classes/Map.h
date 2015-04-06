//
// Created by glados on 4/5/15.
//

#ifndef CC3K_MAP_H
#define CC3K_MAP_H

#include <iostream>
#include <vector>

class MapCell;
class ObjectUnit;
class Chamber;

class Map {
public:
    // public fields
    const static int FLOOR_WIDTH = 79;
    const static int FLOOR_HEIGHT = 25;

    const static int NUMBER_OF_FLOORS = 5;
    const static int NUMBER_OF_CHAMBERS = 5;

    const static char CELL_BLANK = ' ';
    const static char CELL_WALL_HORIZONTAL = '-';
    const static char CELL_WALL_VERTICAL = '|';
    const static char CELL_FLOOR = '.';             // note: representation is unoccupied, though not necessarily the case
    const static char CELL_DOORWAY = '+';
    const static char CELL_PASSAGE = '#';

    // public methods
    static Map& getInstance() {
        static Map instance;
        return instance;
    }                                               // Singleton

    void draw_map(char const * map_file_name);      // Reads in map data, found in the file name, creates MapCells
    void spawn_units();                             // Creates ObjectUnits and populate them in MapCells
    void clear_map();                               // Deletes all ObjectUnits
    void print_map(std::ostream& out);              // Prints the board, according to the game display standards

    MapCell* get_map_cell(int x, int y);            // Accessor of the requested cell, NULL if out of bound

private:
    // private fields
    std::vector<std::vector<MapCell*> > landscape;  // Vector matrix of MapCell pointers
    std::vector<ObjectUnit*> units;                 // Vector of ObjectUnits on map (floor)
    std::vector<Chamber> chambers;                  // Vector of Chambers on map (floor)

    // private methods
    Map();                      // Constructor
    ~Map();                     // Destructor
    Map(Map const&);            // Preventing copies of Singleton
    void operator=(Map const&); // Preventing copies of Singleton

    void update_neighbors();
    void move_randomly();
};


#endif //CC3K_MAP_H
