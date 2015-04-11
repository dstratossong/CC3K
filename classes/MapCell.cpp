//
// Created by glados on 4/6/15.
//

#include "MapCell.h"
#include "Map.h"

void MapCell::despawn() {
    if (cell_type != Map::CELL_FLOOR)
        return;

    if (!object)
        return;

    object->map->remove_unit(object);

    delete object;
    object = NULL;
}

MapCell::~MapCell() {
    delete object;
}
