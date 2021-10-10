#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "Movies/Files with h/container.h"

void errMessage1() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }
    std::cout << "Start\n";

    container container;
    init(container);

    if (!strcmp(argv[1], "-f")) {
        std::ifstream inputFStream(argv[2]);
        in(container, inputFStream);
    } else {
        if (!strcmp(argv[1], "-n")) {
            auto size = atoi(argv[2]);
            if ((size < 1) || (size > 10000)) {
                std::cout << "incorrect number of plants = "
                          << size
                          << ". Set 0 < number <= 10000\n";
                return 3;
            }
            // системные часы в качестве инициализатора.
            srand(static_cast<unsigned int>(time(0)));
            // Заполнение контейнера генератором случайных чисел.
            inRnd(container, size);
        } else {
            errMessage2();
            return 2;
        }
    }

    // Вывод содержимого контейнера в файл.
    std::ofstream outFStream1(argv[3]);
    outFStream1 << "Filled container:\n";
    out(container, outFStream1);

    // The 2nd part of task.
    shakerSort(container, container.lenght);
    std::ofstream outFStream2(argv[4]);
    outFStream2 << "Sorted container:\n";
    out(container, outFStream2);

    clear(container);
    std::cout << "Stop\n";
    return 0;
}
