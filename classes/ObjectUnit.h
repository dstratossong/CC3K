//
// Created by glados on 4/5/15.
//

#ifndef CC3K_OBJECTUNIT_H
#define CC3K_OBJECTUNIT_H

#include <iostream>

class Map;
class MapCell;

class ObjectUnit {
public:
    const static char SYMBOL_HUMAN = '@';
    const static char SYMBOL_DWARF = '@';
    const static char SYMBOL_ELF = '@';
    const static char SYMBOL_ORC = '@';
    const static char SYMBOL_VAMPIRE = 'V';
    const static char SYMBOL_WEREWOLF = 'W';
    const static char SYMBOL_TROLL = 'T';
    const static char SYMBOL_GOBLIN = 'N';
    const static char SYMBOL_MERCHANT = 'M';
    const static char SYMBOL_DRAGON = 'D';
    const static char SYMBOL_PHOENIX = 'X';


    Map* map;
    MapCell* parent;

    int pos_x;
    int pos_y;
    char display_symbol;

    virtual ~ObjectUnit() = 0;

    bool move(int new_x, int new_y); // returns true for success
    bool move(char direction);
    void move_randomly();

protected:
    ObjectUnit(Map* map, MapCell* parent, int pos_x, int pos_y, char display_symbol)
            : pos_x(pos_x), pos_y(pos_y), display_symbol(display_symbol)
    {
        if (!map || !parent)
            throw;

        this->map = map;
        this->parent = parent;
    }

private:


};


#endif //CC3K_OBJECTUNIT_H
