//
// Created by Артем Аросланкин on 06/06/2019.
//

#ifndef LIFE_POOL_COMMON_H
#define LIFE_POOL_COMMON_H

#include <iostream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
#include <random>

using namespace std;


typedef size_t coord_t;

struct Pair
{
    coord_t x; // 0..M-1
    coord_t y; // 0..N-1
};

const size_t N = 20;
const size_t M = 50;

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'


#define VISION_NORMAL 5
#define VISION_HUNT 7

#define HP_PREDATOR 30
#define HP_PREY 20
#define HP_STONE 300

#define REPROUDE_TIME 5

#endif //LIFE_POOL_COMMON_H
