//
// Created by Артем Аросланкин on 06/06/2019.
//

#include "Stone.h"
#include "Cell.h"
#include "Object.h"


Stone::Stone(Cell* _cell) :Object(_cell) {
                reprodue_time = 0;
                hp = HP_STONE;
                type = ObjType::STONE;
                shape = STONE_N;
        }

char Stone::get_char() const {
    return STONE_N;
}

bool Stone::live() {
    if(hp--)
        return true;
    return false;
}