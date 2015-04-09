//
// Created by glados on 4/5/15.
//

#ifndef CC3K_HUMAN_H
#define CC3K_HUMAN_H


#include "../Character.h"

class Human : Character {
public:
    const static int BASE_HIT_POINT = 140;
    const static int BASE_ATTACK_POINT = 20;
    const static int BASE_DEFENCE_POINT = 20;

    Human() {
        hit_point = BASE_HIT_POINT;
        attack_point = BASE_ATTACK_POINT;
        defence_point = BASE_DEFENCE_POINT;
        race_name = "Human";
    }
};


#endif //CC3K_HUMAN_H
