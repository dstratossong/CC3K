//BASE_DEFENCE_POINT
// Created by glados on 4/5/15.
//

#include <stdlib.h>
#include <math.h>
#include "Character.h"
#include "MapCell.h"
#include "items/Potion.h"
#include "Map.h"
#include "RandomUtility.h"

Character::~Character() {};

bool Character::attack(int direction) {
    switch (direction) {
        case Map::DIRECTION_N:
            return attack(pos_x-1, pos_y);
        case Map::DIRECTION_NW:
            return attack(pos_x-1, pos_y-1);
        case Map::DIRECTION_NE:
            return attack(pos_x-1, pos_y+1);
        case Map::DIRECTION_W:
            return attack(pos_x, pos_y-1);
        case Map::DIRECTION_E:
            return attack(pos_x, pos_y+1);
        case Map::DIRECTION_S:
            return attack(pos_x+1, pos_y);
        case Map::DIRECTION_SW:
            return attack(pos_x+1, pos_y-1);
        case Map::DIRECTION_SE:
            return attack(pos_x+1, pos_y+1);
        default:
            return false;
    }
}

bool Character::attack(int target_x, int target_y) {
    MapCell* target_cell = map->get_map_cell(target_x, target_y);

    if (!target_cell)
        return false;

    if (target_cell->cell_type != map->CELL_FLOOR)
        return false;

    if (target_cell->object == NULL)
        return false;

    Character& target = dynamic_cast<Character&>(*(target_cell->object));
    attack(target);

    return true;
}

void Character::attack(Character& defender) {
    // special abilities (future)

    // miss chance
    bool missed = RandomUtility::get_random_integer(100) < (this->miss_chance);
    if (missed)
        return;

    defender.defend(*this);
}

void Character::defend(Character& attacker) {
    // damage calculation
    int damage = (int) ceil(((double) 100)
                            / ((double) 100 + (double) defence_point)
                            * ((double) attacker.attack_point));

    // death
    if (hit_point <= damage)
        return despawn();
    else
        hit_point -= damage;

    std::cout << "DEBUG::target->hit_point " << hit_point << std::endl;
}

void Character::take_potion(Potion& potion) {

}

void Character::gain_gold() {

}

void Character::despawn() {

}
