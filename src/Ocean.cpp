//
// Created by Артем Аросланкин on 06/06/2019.
//

#include "Ocean.h"
#include "Stone.h"
#include "Object.h"

Ocean::Ocean() {
    cells = new Cell*[N];
    for (size_t i(0); i < N; i++) {
        cells[i] = new Cell[M];
        for (size_t j(0); j < M; j++)
            cells[i][j].init({i, j}, this);
    }
}


Ocean::~Ocean() {
    for (int i(0); i < N; i++)
        delete[] cells[i];

    delete[] cells;
    for (auto obj : stuff)
        delete obj;
}


void Ocean::print() const {
    for (int i(0); i < N; i++)
    {
        for (int j(0); j < M; j++)
            cout << (cells[i][j].getObject() ? cells[i][j].getObject()->get_char() : '.');
        cout << endl;
    }
}

void Ocean::switcher(ObjType type) {

}

void Ocean::addStuff(Object *obj) {
    stuff.push_back(obj);
}

void Ocean::deleteObject(Object *object) {
    object->getCell()->killMe();
}



void Ocean::addObjects(ObjType type, unsigned int number) {
    for(int i = 0; i < number;i++) {
        int k = 0;
        int x = rand() % N;
        int y = rand() % M;
        while(cells[x][y].getObject()!= nullptr && k < N*M){
            int x = rand() % N;
            int y = rand() % M;
            k++;
        }
        Object* object = nullptr;
        if(k==N*M){
            for(int i = 0; i < N; i++)
                for(int j = 0; j < M; j++){
                    if(cells[i][j].getObject()== nullptr) {
                        switch (type) {
                            case ObjType::PREDATOR:
                                object = new Predator(&cells[i][j]);
                                break;
                            case ObjType::PREY:
                                object = new Prey(&cells[i][j]);
                                break;
                            case ObjType::STONE:
                                object = new Stone(&cells[i][j]);
                                break;
                            default:
                                break;
                        }
                        this->addStuff(object);
                        cells[i][j].setObject(object);
                    }
                }
        }
        else{
            switch(type)
            {
                case ObjType::PREDATOR:
                    object = new Predator(&cells[x][y]);
                    break;
                case ObjType::PREY:
                    object = new Prey(&cells[x][y]);
                    break;
                case ObjType::STONE:
                    object = new Stone(&cells[x][y]);
                    break;
                default:
                    break;
            }
            this->addStuff(object);
            cells[x][y].setObject(object);
        }


    }
}


void Ocean::kill(Object *obj)
{
    obj->getCell()->killMe();
}

Cell* Ocean::search_empty_cell(Pair crd) {
    for(int i =0; i < VISION_NORMAL; i ++){
        size_t x_n = crd.x + rand() % 3 - 1;
        size_t y_n = crd.y + rand() % 3 - 1;
        if (x_n < N && y_n < M)
            if (cells[x_n][y_n].getObject() == nullptr)
                return &cells[x_n][y_n];
    }
    return nullptr;
}

Cell* Ocean::search_prey(Pair crd) const {
    for (int i(0); i < VISION_HUNT; i++) {
        size_t x_n = crd.x + rand() % 3 - 1;
        size_t y_n = crd.y + rand() % 3 - 1;
        if (x_n < N && y_n < M)
            if (cells[x_n][y_n].getObject() && cells[x_n][y_n].getObject()->getType() == ObjType::PREY)
                return &cells[x_n][y_n];
    }
    return nullptr;
}

void Ocean::run() {
    for(auto i = stuff.begin(); i != stuff.end();i++){
        if((*i)->live() == false){
            deleteObject(*i);
            stuff.erase(i++);
        }
    }
}