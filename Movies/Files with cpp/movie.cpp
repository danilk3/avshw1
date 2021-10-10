// Copyright 2021 Kotelnikov D
#include "../Files with h/movie.h"
// Метод возвращающий содерживое ошибки.
std::string errMessage1() {
    return "incorrect name of movie:!\n"
           "Waited:\n"
           "FICTION = 0,\n"
           "CARTOON = 1,\n"
           "DOCUMENTARY = 2\n";
}

// Ввод обобщения фильма.
movie *in(std::ifstream &inputFStream) {
    movie *someMovie;
    int typeOfMovie;
    inputFStream >> typeOfMovie;
    switch (typeOfMovie) {
        case 0:
            someMovie = new movie;
            someMovie->typeOfMovie = movie::FICTION;
            in(someMovie->someDocumentary, inputFStream);
            return someMovie;
        case 1:
            someMovie = new movie;
            someMovie->typeOfMovie = movie::CARTOON;
            in(someMovie->someFiction, inputFStream);
            return someMovie;
        case 2:
            someMovie = new movie;
            someMovie->typeOfMovie = movie::DOCUMENTARY;
            in(someMovie->someCartoon, inputFStream);
            return someMovie;
        default:
            return nullptr;
    }
}

// Случайный ввод обобщения фильма.
movie *inRnd() {
    movie *someMovie;
    auto typeOfMovie = std::rand() % 3;
    switch (typeOfMovie) {
        case 0:
            someMovie = new movie;
            someMovie->typeOfMovie = movie::FICTION;
            inRnd(someMovie->someDocumentary);
            return someMovie;
        case 1:
            someMovie = new movie;
            someMovie->typeOfMovie = movie::CARTOON;
            inRnd(someMovie->someFiction);
            return someMovie;
        case 2:
            someMovie = new movie;
            someMovie->typeOfMovie = movie::DOCUMENTARY;
            inRnd(someMovie->someCartoon);
            return someMovie;
        default:
            return nullptr;

    }
}

// Вывод обобщения фильма.
void out(movie &someMovie, std::ofstream &outFStream) {
    switch (someMovie.typeOfMovie) {
        case movie::FICTION:
            out(someMovie.someFiction, outFStream);
            break;
        case movie::CARTOON:
            out(someMovie.someDocumentary, outFStream);
            break;
        case movie::DOCUMENTARY:
            out(someMovie.someCartoon, outFStream);
            break;
        default:
            outFStream << errMessage1;
    }
    outFStream << "\n";
}

// Параметр сортировки.
double comparisonParameter(movie &someMovie) {
    switch (someMovie.typeOfMovie) {
        case movie::FICTION:
            return comparisonParameter(someMovie.someFiction);
        case movie::CARTOON:
            return comparisonParameter(someMovie.someDocumentary);
        case movie::DOCUMENTARY:
            return comparisonParameter(someMovie.someCartoon);
        default:
            return -1;
    }
}