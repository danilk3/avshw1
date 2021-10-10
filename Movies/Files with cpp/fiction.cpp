// Copyright 2021 Kotelnikov D
#include "../Files with h/fiction.h"

// Ввод параметров игрового фильма из файла.
void in(fiction &someFiction, std::ifstream &inputFStream) {
    inputFStream >> someFiction.name >> someFiction.director >> someFiction.releaseDate;
}

// Случайный ввод параметров игрового фильма.
void inRnd(fiction &someFiction) {
    randomName(someFiction.name, sizeName);
    randomName(someFiction.director, sizeName);
    someFiction.releaseDate = randomParam(2021);
}

// Вывод параметров игрового фильма в форматируемый поток.
void out(fiction &someFiction, std::ofstream &outFStream) {
    outFStream << "It is Fiction: name = " << someFiction.name << ", director = " << someFiction.director
               << ", release date = " << someFiction.releaseDate;
}

// Частное от деления числа гласных букв в названии на общую длину названия.
double comparisonParameter(fiction &someFiction) {
    return someFiction.releaseDate / (sizeof(someFiction.name) / sizeof(someFiction.name[0]));
}

