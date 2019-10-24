//
// Created by Nebulino on 10/24/19.
//

#include <iostream>
#include <cassert>

#include "dbuffer.h"


// Always put qualifier-id
dbuffer::dbuffer() {

    _size = 0;
    _buffer = nullptr;

#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer()" << std::endl;
#endif

}

dbuffer::dbuffer(unsigned int size) {

    _buffer = new int[size];
    this -> _size = size;

#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer(unsigned int _size)" << std::endl;
#endif

}

dbuffer::dbuffer(unsigned int size, int value) {

    _buffer = new int[size];
    this -> _size = size;

    // IN C++ you can't call another constructor with a constructor
    // Create a private method? A helper method
    for(int i=0; i<size; ++i) {
        _buffer[i] = value;
    }

#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer(unsigned int _size, int value)" << std::endl;
#endif

}

dbuffer::~dbuffer() {

    delete[] _buffer;

    _buffer = nullptr;
    _size = 0;

#ifndef NDEBUG
    std::cout << "dbuffer::~dbuffer()" << std::endl;
#endif

}

int dbuffer::getValue(unsigned int index) {

    assert(index < this -> _size);
    return this -> _buffer[index];

}

void dbuffer::setValue(unsigned int index, int value) {

    assert(index < this -> _size);
    this -> _buffer[index] = value;
}

int &dbuffer::value(unsigned int index) {

    assert(index < this -> _size);
    return this -> _buffer[index];

}

unsigned int dbuffer::size() {

    return this -> _size;

}

dbuffer& dbuffer::operator=(const dbuffer &rhs) {

    // this is the lhs (left hand size)

    // Check if rhs is not this, by using pointers.
    // Check if the addresses are not the same. Avoiding the auto-assignment
    // This is a pointer. also &rhs.
    if (this != &rhs) {
        // ...
    }

    return *this; // I need do de-reference it...

    // Useful for instruction like... a = b =c || a = (b = c) means := put on a the result of b = c

}

