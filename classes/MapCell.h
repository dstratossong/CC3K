//
// Created by glados on 4/6/15.
//

#ifndef CC3K_MAPCELL_H
#define CC3K_MAPCELL_H

#include <iostream>
#include <vector>
#include "ObjectUnit.h"

class ObjectUnit;

class MapCell {
public:
    int pos_x;
    int pos_y;
    char cell_type; // one of constants from Map
    std::vector<MapCell*> neighbors; // neighboring cells within 1 block radius
    ObjectUnit* object; // encasing object

    MapCell(int pos_x, int pos_y, char cell_type)
            : pos_x(pos_x), pos_y(pos_y), cell_type(cell_type), object(NULL) {};
    ~MapCell();

private:

};


#endif //CC3K_MAPCELL_H
