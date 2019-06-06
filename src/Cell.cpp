//
// Created by Артем Аросланкин on 06/06/2019.
//

#include "Cell.h"

void Cell::init(Pair p, Ocean *oc) {
    ocean = oc;
    crd = p;
}


Object* Cell::getObject() const {
    return this->obj;
}


Ocean* Cell::getOcean() const {
    return this->ocean;
}


void Cell::setObject(Object* obj) {
    this->obj = obj;
}


void Cell::killMe() {
    if (obj) {
        delete obj;
        obj = nullptr;
    }
}

Cell* Cell::search_empty_cell() {
    return ocean->search_empty_cell(crd);
}

Cell* Cell::search_prey() {
    return ocean->search_prey(crd);
}