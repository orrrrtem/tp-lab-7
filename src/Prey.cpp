//
// Created by Артем Аросланкин on 06/06/2019.
//

#include "Prey.h"
#include "Cell.h"
#include "Object.h"

Prey::Prey(Cell* _cell) :Object(_cell){
                hp = HP_PREY;
                reprodue_time = REPROUDE_TIME;
                type = ObjType::PREY;
                shape = PREY_N;
        }

bool Prey::live() {
    if(!hp--)
        return false;
    move();
    reprodue_time--;
    if(reprodue_time == 0)
            reproduce();
    reprodue_time = REPROUDE_TIME;
    return true;
}


char Prey::get_char() const {
    return PREY_N;
}

void Prey::move() {
    Cell* new_cell = cell->search_empty_cell();
    if(new_cell){
        cell->setObject(nullptr);
        cell = new_cell;
        new_cell->setObject(this);
    }
}

void Prey::reproduce() {
    Cell* new_cell = cell->search_empty_cell();
    if(new_cell){
        auto* child = new Predator(new_cell);
        new_cell->setObject(child);
        new_cell->getOcean()->addStuff(child);
    }
}