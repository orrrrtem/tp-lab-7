//
// Created by Артем Аросланкин on 06/06/2019.
//

#include "Predator.h"
#include "Cell.h"
#include "Object.h"


Predator::Predator(Cell* cell): Object(cell) {
                hp = HP_PREDATOR;
                reprodue_time = REPROUDE_TIME;
                type = ObjType::PREDATOR;
                shape = PREDATOR_N;
        }

bool Predator::live() {
    if(!hp--)
        return false;
    is_hungry =!eat();
    reprodue_time--;
    move();
    if(reprodue_time == 0)
        if(!is_hungry)
            reproduce();
    reprodue_time = REPROUDE_TIME;
    return true;
}

char Predator::get_char() const {
    return PREDATOR_N;
}

bool Predator::eat() {
    Cell* victim =  cell->search_prey();
    if(victim!= nullptr){
        victim->getObject()->set_hp(0);
        return true;
    }
    return false;

}

void Predator::move(){
    Cell* new_cell = cell->search_empty_cell();
    if(new_cell){
        cell->setObject(nullptr);
        cell = new_cell;
        new_cell->setObject(this);
    }
}

void Predator::reproduce() {
    Cell* new_cell = cell->search_empty_cell();
    if(new_cell){
        auto* child = new Predator(new_cell);
        new_cell->setObject(child);
        new_cell->getOcean()->addStuff(child);
    }
}