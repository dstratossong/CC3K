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

    const static int FIRST_FLOOR = 1;
    const static int NUMBER_OF_FLOORS = 5;
    const static int NUMBER_OF_CHAMBERS = 5;

    const static char CELL_BLANK = ' ';
    const static char CELL_WALL_HORIZONTAL = '-';
    const static char CELL_WALL_VERTICAL = '|';
    const static char CELL_FLOOR = '.';             // note: representation is unoccupied, though not necessarily the case
    const static char CELL_DOORWAY = '+';
    const static char CELL_PASSAGE = '#';

    const static int DIRECTION_N = 0;
    const static int DIRECTION_NE = 1;
    const static int DIRECTION_E = 2;
    const static int DIRECTION_SE = 3;
    const static int DIRECTION_S = 4;
    const static int DIRECTION_SW = 5;
    const static int DIRECTION_W = 6;
    const static int DIRECTION_NW = 7;

    // public methods
    static Map& getInstance() {
        static Map instance;
        return instance;
    }                                               // Singleton

    void draw_map(char const * map_file_name);      // Reads in map data, found in the file name, creates MapCells
    void update_neighbors();                        // Updates the list of neighbors of each MapCell
    void spawn_units();                             // Creates ObjectUnits and populate them in MapCells
    void clear_map();                               // Deletes all ObjectUnits
    void print_map(std::ostream& out);              // Prints the board, according to the game display standards
    void move_randomly();                           //

    MapCell* get_map_cell(int x, int y);            // Accessor of the requested cell, NULL if out of bound
    void remove_unit(ObjectUnit* unit);

private:
    // private fields
    std::vector<std::vector<MapCell*> > landscape;  // Vector matrix of MapCell pointers
    std::vector<ObjectUnit*> units;                 // Vector of ObjectUnits on map (floor)
    std::vector<Chamber> chambers;                  // Vector of Chambers on map (floor)

    // private methods
    Map();                   // Constructor
    ~Map();                     // Destructor

    Map(Map const&);            // Preventing copies of Singleton
    void operator=(Map const&); // Preventing copies of Singleton

    // Spawning - see Registry Pattern
    MapCell* get_spawning_ground(int pos_x, int pos_y);
    void spawn_human(int pos_x, int pos_y);
    void spawn_dwarf(int pos_x, int pos_y);
    void spawn_elves(int pos_x, int pos_y);
    void spawn_orc(int pos_x, int pos_y);
    void spawn_vampire(int pos_x, int pos_y);
    void spawn_werewolf(int pos_x, int pos_y);
    void spawn_troll(int pos_x, int pos_y);
    void spawn_goblin(int pos_x, int pos_y);
    void spawn_merchant(int pos_x, int pos_y);
    void spawn_dragon(int pos_x, int pos_y);
    void spawn_phoenix(int pos_x, int pos_y);
};


#endif //CC3K_MAP_H
