// Copyright 2021 Kotelnikov D
#include <cctype>
#include "../Files with h/randomGenerator.h"
int randomParam(int item) {
    return std::rand() % item;
}

void randomName(char *content, int size) {
    content[0] = toupper(char('a' + std::rand() % 26 - 1));
    for (int i = 1; i < size; ++i) {
        content[i] = char('a' + std::rand() % 26 - 1);
    }
    content[size] = '\0';
}