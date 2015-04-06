//
// Created by glados on 4/5/15.
//

#ifndef CC3K_OBJECTUNIT_H
#define CC3K_OBJECTUNIT_H

class Map;
class MapCell;

class ObjectUnit {
public:
    int pos_x;
    int pos_y;
    MapCell* parent;
    Map* map;

    virtual ~ObjectUnit() = 0;
    // TODO: virtual destructor

private:
    bool move(int new_x, int new_y); // returns true for success
    bool move(char direction);
    void move_randomly();
};


#endif //CC3K_OBJECTUNIT_H
