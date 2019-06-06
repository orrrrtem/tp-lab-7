//
// Created by Артем Аросланкин on 06/06/2019.
//

#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"

class Stone: public Object{
protected:
public:
    Stone(Cell* _cell);
    ~Stone() = default;
    bool live() override;
    char get_char() const override;
};

//#endif //LIFE_POOL_STONE_H
