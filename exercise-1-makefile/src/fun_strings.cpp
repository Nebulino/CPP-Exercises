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

char *concatenate_strings(const char *str1, const char *str2) {

    int sz1 = len_string(str1);
    int sz2 = len_string(str2);

    char *new_string = new char[sz1 + sz2 + 1]; // +1 because of the /0

    for (int i=0; i < sz1; ++i) {
        new_string[i] = str1[i];
    }

    for (int i=0; i < sz1+sz2+1; ++i) {
        new_string[i] = str2[i-sz1];
    }

    return new_string;
}

const char *search_a_string(const char *str, const char *str_t) {
    int sz = len_string(str);
    int sz_t = len_string(str_t);

    for (int i=0; i < sz; ++i) {
        int j = 0;

        while((j < sz_t) && (i+j < sz) && (str[i+j] == str_t[i])) {
            ++j;
        }

        if (j == sz_t) {
            return str+i;
        }

        if (i+j >= sz) {
            return nullptr;
        }
    }

    return nullptr;
}

void find_replace_string(char *str, const char *str_t, const char *s) {

    int sz_t = len_string(str_t);
    int szs = len_string(s);

    assert(sz_t == szs);

    char *token = const_cast<char *>(search_a_string(str, str_t));

    if (token != nullptr) {
        for (int i=0; i<sz_t; ++i) {
            token[i] = s[i];                      // t[i] : poits the starting string
        }}

   token = const_cast<char *>(search_a_string(str_t + szs, str_t));
}

