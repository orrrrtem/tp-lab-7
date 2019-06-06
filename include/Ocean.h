//
// Created by Артем Аросланкин on 06/06/2019.
//

#pragma once

#include "Common.h"
#include "Cell.h"
#include "Prey.h"
#include "Predator.h"
#include "Stone.h"

class Object;
class Cell;

class Ocean
{
   // friend Object;
    friend Cell;

private:
    Cell **cells;
    list<Object*> stuff;
    int size_pred = 0;
    int size_prey = 0;

public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(ObjType type, unsigned int number);
    void deleteObject(Object *ojb);
    void addStuff(Object* obj);
    void run();
    void eat();
    void kill(Object *obj);
    void produce();
    Cell* search_prey(Pair crd) const;
    Cell* search_empty_cell(Pair crd);
    void switcher(ObjType type);
};
//#endif //LIFE_POOL_OCEAN_H
