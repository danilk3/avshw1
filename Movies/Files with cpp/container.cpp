// Copyright 2021 Kotelnikov D
#include "../Files with h/container.h"

// Инициализация данных.
void init(container &container) {
    container.lenght = 0;
}

// Отчистка данных.
void clear(container &container) {
    for (int i = 0; i < container.lenght; i++) {
        delete container.data[i];
    }
    container.lenght = 0;
}

// Ввод данных в поток.
void in(container &container, std::ifstream &inputFStream) {
    while (!inputFStream.eof()) {
        if ((container.data[container.lenght] = in(inputFStream)) != 0) {
            container.lenght++;
        }
    }
}

// Ввод случайных данных в форматируемый поток.
void inRnd(container &container, int size) {
    while (container.lenght < size) {
        container.data[container.lenght] = inRnd();
        if (container.data[container.lenght] != nullptr) {
            container.lenght++;
        }
    }
}

// Вывод данных.
void out(container &container, std::ofstream &outFStream) {
    outFStream << "Container contains " << container.lenght << " elements.\n";
    for (int i = 0; i < container.lenght; i++) {
        outFStream << i << ": ";
        out(*(container.data[i]), outFStream);
    }
}

// Меняем местами элементы.
void swap(movie *a, movie *b) {
    movie plant= *a;
    *a = *b;
    *b = plant;
}

// Упорядочить элементы контейнера по убыванию используя шейкерную сортировку (Shaker Sort).
void shakerSort(container &container, int n) {
    int left, right, i;
    left = 0;
    right= n - 1;
    while (left <= right) {
        for (i = right; i >= left; i--) {
            if (container.data[i-1] > container.data[i]) {
                swap(container.data[i-1], container.data[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++) {
            if (container.data[i-1] > container.data[i]) {
                swap(container.data[i-1], container.data[i]);
            }
        }
        right--;
    }
}
