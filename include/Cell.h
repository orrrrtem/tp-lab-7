//
// Created by Артем Аросланкин on 06/06/2019.
//

#pragma once

#include "Common.h"
#include "Object.h"
#include "Ocean.h"

//class Object;
//class Ocean;

class Cell
{
    friend Ocean;
private:
    Pair crd;
    Object* obj;
    Ocean *ocean;
public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
            crd(p),
            obj(nullptr),
            ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    Ocean* getOcean() const;
    void setObject(Object*);
    void killMe();
    Cell* search_prey();
    Cell* search_empty_cell();
};

//#endif //LIFE_POOL_CELL_H
