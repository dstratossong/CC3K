//
// Created by glados on 4/5/15.
//

#ifndef CC3K_CHARACTER_H
#define CC3K_CHARACTER_H

#include <iostream>
#include "ObjectUnit.h"

class Character : public ObjectUnit {
public:
    int hit_point;
    int attack_point;
    int defence_point;

    std::string race_name;

    virtual ~Character() = 0;

    void attack(Character& other_character);
    void take_hit();
    void take_potion();
    void gain_gold();

protected:
    Character(Map* map, MapCell* parent, int pos_x, int pos_y, char display_symbol, int hit_point, int attack_point, int defence_point, std::string race_name)
            : ObjectUnit(map, parent, pos_x, pos_y, display_symbol),
              hit_point(hit_point),
              attack_point(attack_point),
              defence_point(defence_point),
              race_name(race_name)
    {};

private:

};


#endif //CC3K_CHARACTER_H
