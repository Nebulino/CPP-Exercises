#include <iostream>

#include "fun_strings.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "No input string" << std::endl;
        return 2;
    }

    std::cout << "The string is: " << std::endl;
    print_string(argv[1]);

    std::cout << "The string length is: " << len_string(argv[1]) << std::endl;

    invert_string(argv[1]);
    std::cout << "The inverted string is: " << argv[1]<< std::endl;

    char *cloned_string = string_clone(argv[1]);
    std::cout << "The string (cloned) is: " << cloned_string << std::endl;

    delete[] cloned_string;
    cloned_string = nullptr;

    return 0;
}