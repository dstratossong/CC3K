//
// Created by glados on 4/6/15.
//

#ifndef CC3K_VAMPIRE_H
#define CC3K_VAMPIRE_H


#include "../Character.h"

class Vampire : public Character {
public:
    const static int BASE_HIT_POINT = 50;
    const static int BASE_ATTACK_POINT = 25;
    const static int BASE_DEFENCE_POINT = 25;

    Vampire(Map* map, MapCell* parent, int pos_x, int pos_y)
    : Character(map, parent, pos_x, pos_y, SYMBOL_VAMPIRE, BASE_HIT_POINT, BASE_ATTACK_POINT, BASE_DEFENCE_POINT, "Vampire")
    {};
    ~Vampire() {};

};


#endif //CC3K_VAMPIRE_H
