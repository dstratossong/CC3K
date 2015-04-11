//
// Created by glados on 4/5/15.
//

#ifndef CC3K_CHARACTER_H
#define CC3K_CHARACTER_H

#include <iostream>
#include "ObjectUnit.h"

class Potion;

class Character : public ObjectUnit {
public:
    virtual ~Character() = 0;

    int get_hit_point() {
        return hit_point;
    }

    bool attack(int direction);

    virtual void take_potion(Potion& potion);
    virtual void gain_gold();

protected:
    Character(Map* map, MapCell* parent, int pos_x, int pos_y, char display_symbol, int hit_point, int attack_point, int defence_point, int miss_chance, std::string race_name)
            : ObjectUnit(map, parent, pos_x, pos_y, display_symbol),
              hit_point(hit_point),
              attack_point(attack_point),
              defence_point(defence_point),
              miss_chance(miss_chance),
              race_name(race_name) {};

private:
    int hit_point;
    int attack_point;
    int defence_point;
    int miss_chance;

    std::string race_name;

    bool attack(int target_x, int target_y);
    void attack(Character& defender);
    void defend(Character& attacker);
    void despawn();
};


#endif //CC3K_CHARACTER_H
