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

    void attack(Character& other_character);
    void take_hit();
    void take_potion();
    void gain_gold();

private:
};


#endif //CC3K_CHARACTER_H
