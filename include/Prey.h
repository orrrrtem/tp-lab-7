//
// Created by Артем Аросланкин on 06/06/2019.
//

#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"


class Prey: public Object{
protected:
public:
    Prey(Cell* _cell);
    bool live() override;
    char get_char() const override;
    void move() override;
    void reproduce() override;
};



//#endif //LIFE_POOL_PREY_H
