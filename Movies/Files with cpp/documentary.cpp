// Copyright 2021 Kotelnikov D
#include "../Files with h/documentary.h"

// Ввод параметров документально фильма.
void in(documentary &someDocumentary, std::ifstream &inputFStream) {
    inputFStream >> someDocumentary.name >> someDocumentary.minutes >> someDocumentary.releaseDate;
}

// Случайное заполнение параметров документально фильма.
void inRnd(documentary &someDocumentary) {
    someDocumentary.minutes = randomParam(1000);
    someDocumentary.releaseDate = randomParam(2021);
    randomName(someDocumentary.name, sizeName);
}

// Вывод параметров документально фильма в форматируемый поток.
void out(documentary &someDocumentary, std::ofstream &outFStream) {
    outFStream << "It is Documentary: name = " << someDocumentary.name <<
         ", minutes = " << someDocumentary.minutes << ", release date = " << someDocumentary.releaseDate;
}

// Параматр для сравнения.
double comparisonParameter(documentary &someDocumentary) {
    return someDocumentary.releaseDate / (sizeof(someDocumentary.name) / sizeof(someDocumentary.name[0]));
}