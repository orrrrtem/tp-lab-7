//
// Created by Артем Аросланкин on 06/06/2019.
//

#include "Object.h"


Object::Object(Cell *c) : cell(c) {}


Cell* Object::getCell() const {
    return this->cell;
}


ObjType Object::getType() const {
    return this->type;
}


void Object::set_hp(int hp){
    this->hp = hp;
}


