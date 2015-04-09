//
// Created by glados on 4/5/15.
//

#ifndef CC3K_HUMAN_H
#define CC3K_HUMAN_H


#include "../Character.h"

class Human : public Character {
public:
    const static int BASE_HIT_POINT = 140;
    const static int BASE_ATTACK_POINT = 20;
    const static int BASE_DEFENCE_POINT = 20;

    Human(Map* map, MapCell* parent, int pos_x, int pos_y)
            : Character(map, parent, pos_x, pos_y, SYMBOL_HUMAN, BASE_HIT_POINT, BASE_ATTACK_POINT, BASE_DEFENCE_POINT, "Human")
    {};
    ~Human() {};
};


#endif //CC3K_HUMAN_H
