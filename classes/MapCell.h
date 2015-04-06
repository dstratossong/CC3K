//
// Created by glados on 4/6/15.
//

#ifndef CC3K_MAPCELL_H
#define CC3K_MAPCELL_H


#include "ObjectUnit.h"

class MapCell {
public:
    int pos_x;
    int pos_y;
    char cell_type; // one of constants from Map
    MapCell** neighbors; // neighboring cells within 1 block radius
    ObjectUnit* object; // encasing object
private:

};


#endif //CC3K_MAPCELL_H
