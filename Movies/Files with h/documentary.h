// Copyright 2021 Kotelnikov D
#ifndef AVSHOMEWORK1_DOCUMENTARY_H
#define AVSHOMEWORK1_DOCUMENTARY_H
#include <fstream>
#include "constants.h"
#include "randomGenerator.h"
struct documentary {
    int minutes;
    char name[sizeName];
    int releaseDate;
};

// Ввод параметров документального фильма из файла.
void in(documentary &someDocumentary, std::ifstream &inputFStream);

// Случайный ввод параметров документального фильма.
void inRnd(documentary &someDocumentary);

// Вывод параметров документального фильма в форматируемый поток.
void out(documentary &someDocumentary, std::ofstream &outFStream);

// Частное от деления года выхода фильма на количество символов в названии (действительное число).
double comparisonParameter(documentary &someDocumentary);

#endif //AVSHOMEWORK1_DOCUMENTARY_H
