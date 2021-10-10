// Copyright 2021 Kotelnikov D
#include "../Files with h/cartoon.h"

// Ввод параметров мультфильма.
void in(cartoon &someCartoon, std::ifstream &inputFStream) {
    int way;
    inputFStream >> someCartoon.name >> someCartoon.releaseDate >> way;
    someCartoon.wayToCreate = (cartoon::way) way;
}

// Случайное заполнение параметров мультфильма.
void inRnd(cartoon &someCartoon) {
    someCartoon.wayToCreate = (cartoon::way) randomParam(3);
    randomName(someCartoon.name, sizeName);
    someCartoon.releaseDate = randomParam(2021);
}

// Вывод параметров мультфильма в форматируемый поток.
void out(cartoon &someCartoon, std::ofstream &outFStream) {
    outFStream << "It is Cartoon: name = " << someCartoon.name << ", release date" << someCartoon.releaseDate <<
               ", way (DRAWED = 0, PUPPET = 1, PLASTIC = 2): " << static_cast<int>(someCartoon.wayToCreate);
}

// Параматр для сравнения.
double comparisonParameter(cartoon &someCartoon) {
    return someCartoon.releaseDate / (sizeof(someCartoon.name) / sizeof(someCartoon.name[0]));
}