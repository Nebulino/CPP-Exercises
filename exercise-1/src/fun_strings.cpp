//
// Created by Lillie on 10/15/2019.
//

#include <iostream>
#include <cassert>

#include "fun_strings.h"


void print_string(const char *str) {
    assert(str != nullptr);

    const char *current = str;

    while (*current != '\0') {
        std::cout << *current << std::endl;
        current++;
    }
};

unsigned int len_string(const char *str) {
    assert(str != nullptr); // if not false, kills

    const char *current = str;

    while (*current != '\0') {
        current++;
    }

    return static_cast<unsigned int>(current-str);
}

void invert_string(char *str) {
    assert(str != nullptr);

    char *start = str;
    char *end = str + len_string(str) - 1;

    while (start < end) {
        std::swap(*start, *end);
        start++;
        end--;
    }
}

char *string_clone(const char *str) {
    assert(str != nullptr);

    int sz = len_string(str);
    char *out = new char[sz+1];

    //TODO: Check exception -> to the caller -> if not: the OS kills the process

    for (int i = 0; i < sz+1; ++i) {
        out[i] = str[i];
    }

    return out;
}