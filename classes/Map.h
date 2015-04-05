//
// Created by glados on 4/5/15.
//

#ifndef CC3K_MAP_H
#define CC3K_MAP_H


class Map {
public:
    int** landscape;

private:
    const int CELL_WALL = 1;
    const int CELL_FLOOR = 2;
    const int CELL_DOORWAY = 3;
    const int CELL_PASSAGE = 4;
};


#endif //CC3K_MAP_H
