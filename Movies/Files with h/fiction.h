// Copyright 2021 Kotelnikov D
#ifndef AVSHOMEWORK1_FICTION_H
#define AVSHOMEWORK1_FICTION_H
#include <fstream>
#include "constants.h"
#include "randomGenerator.h"

struct fiction {
    int releaseDate;
    char name[sizeName];
    char director[sizeName];
};

// Ввод параметров игровых фильмов из файла.
void in(fiction &someFiction, std::ifstream &inputFStream);

// Случайный ввод параметров цветов.
void inRnd(fiction &someFiction);

// Вывод параметров цветов в форматируемый поток.
void out(fiction &someFiction, std::ofstream &outFStream);

// Частное от деления года выхода фильма на количество символов в названии (действительное число).
double comparisonParameter(fiction &someFiction);

#endif //AVSHOMEWORK1_FICTION_H
