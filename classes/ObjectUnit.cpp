//
// Created by glados on 4/5/15.
//

#include "ObjectUnit.h"
#include "Map.h"
#include "MapCell.h"
#include <iostream>

bool ObjectUnit::move(int new_x, int new_y) {
    MapCell* new_cell = map->get_map_cell(new_x, new_y);

    if (!new_cell)
        return false;

    if (new_cell->cell_type != map->CELL_FLOOR)
        return false;

    if (new_cell->object != NULL)
        return false;

    pos_x = new_x;
    pos_y = new_y;

    parent->object = NULL; // set existing to NULL
    new_cell->object = this;
}

bool ObjectUnit::move(char direction) {

}

void ObjectUnit::move_randomly() {

}

ObjectUnit::~ObjectUnit() {};
