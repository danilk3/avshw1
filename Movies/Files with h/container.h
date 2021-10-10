// Copyright 2021 Kotelnikov D
#ifndef AVSHOMEWORK1_CONTAINER_H
#define AVSHOMEWORK1_CONTAINER_H
#include <fstream>
#include "movie.h"

struct container {
    enum {
        max_len = 10000
    };

    int lenght;
    movie *data[max_len];
};

// Инициализация контейнера.
void init(container &container);

// Очистка контейнера от элементов (освобождение памяти).
void clear(container &container);

// Ввод содержимого контейнера из указанного потока.
void in(container &container, std::ifstream &inputFStream);

// Случайный ввод содержимого контейнера.
void inRnd(container &container, int size);

// Вывод содержимого контейнера в указанный поток.
void out(container &container, std::ofstream &outFStream);

// ---
void swap(movie *a, movie *b);

void shakerSort(container &container, int n);

#endif //AVSHOMEWORK1_CONTAINER_H
