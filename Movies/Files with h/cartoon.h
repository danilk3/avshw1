// Copyright 2021 Kotelnikov D
#ifndef AVSHOMEWORK1_CARTOON_H
#define AVSHOMEWORK1_CARTOON_H
#include <fstream>
#include "constants.h"
#include "randomGenerator.h"

struct cartoon {
    enum way {
        DRAWED = 0,
        PUPPET = 1,
        PLASTIC = 2,
    };
    char name[sizeName];
    int releaseDate;
    way wayToCreate;
};

// Ввод параметров мультфильма из файла.
void in(cartoon &someCartoon, std::ifstream &inputFStream);

// Случайный ввод параметров мультфильма.
void inRnd(cartoon &someCartoon);

// Вывод параметров мультфильма в форматируемый поток.
void out(cartoon &someCartoon, std::ofstream &outFStream);

// Частное от деления года выхода фильма на количество символов в названии (действительное число).
double comparisonParameter(cartoon &someCartoon);;


#endif //AVSHOMEWORK1_CARTOON_H
