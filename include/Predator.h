//
// Created by Артем Аросланкин on 06/06/2019.
//

#pragma once

//#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "Common.h"

class Predator: public Object{
protected:
public:
    Predator(Cell* cell);
    bool live() override;
    char get_char() const override;
    bool eat();
    void move() override;
    void reproduce() override;

private:
    bool is_hungry = true;
};

//#endif //LIFE_POOL_PREDATOR_H
