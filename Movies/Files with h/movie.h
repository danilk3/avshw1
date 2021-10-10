// Copyright 2021 Kotelnikov D
#ifndef AVSHOMEWORK1_MOVIE_H
#define AVSHOMEWORK1_MOVIE_H
#include "documentary.h"
#include "fiction.h"
#include "cartoon.h"

struct movie{
    enum key {
        FICTION = 0,
        CARTOON = 1,
        DOCUMENTARY = 2
    };
    union {
        fiction someFiction;
        cartoon someCartoon;
        documentary someDocumentary;
    };
    key typeOfMovie;
};

// Ввод обобщения растения.
movie *in(std::ifstream &inputFStream);

// Случайный ввод обобщения растения.
movie *inRnd();

// Вывод обобщения растения.
void out(movie &someMovie, std::ofstream &outFStream);

// Параметр сортировки.
double comparisonParameter(movie &someMovie);

#endif //AVSHOMEWORK1_MOVIE_H
