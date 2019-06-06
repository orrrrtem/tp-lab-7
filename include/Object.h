//
// Created by Артем Аросланкин on 06/06/2019.
//

#pragma once

#include "Common.h"




enum class ObjType {STONE,PREY,PREDATOR};

class Cell;
class Ocean;

class Object
{
    friend Ocean;
    friend Cell;

protected:
    Cell* cell;
    int hp;
    char shape;
    ObjType type;
    int reprodue_time;

public:
    Object(Cell * = nullptr);
    virtual ~Object() = default;
    //void setCell(Cell*);
    Cell* getCell() const;
    ObjType getType() const;
    void set_hp(int hp);
    virtual bool live() = 0; // жизнь объекта
    virtual char get_char() const  = 0;
    virtual void move() {};
    virtual void reproduce() {};

};








/*
class Coral: public Object{
protected:
public:
    Coral(Cell* _cell) :Object(_cell)
    {
        type = ObjType::CORAL;
        shape = CORAL_N;
    }
    bool live() override;
    char get_char() const override;
    bool eat();
    void move() override;
    void reproduce() override;
};*/
//#endif //LIFE_POOL_OBJECT_H
