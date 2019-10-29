//
// Created by Nebulino on 10/24/19.
//

#include <iostream>
#include <cassert>
#include <algorithm>

#include "dbuffer.h"


// Always put qualifier-id
dbuffer::dbuffer() : _size(0), _buffer(nullptr) {

    // A way to initialize... before the assignment... by initialization list... using [ : ]
    // calling a copy_constructor to the member variables...
    // : _size(0), _buffer(nullptr)  means int _size = 0; etc...
    // Executed before the constructor itself

    // Another way...
    // _size = 0;
    // _buffer = nullptr;

#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer()" << std::endl;
#endif

}

dbuffer::dbuffer(unsigned int size) : _size(0), _buffer(nullptr) {

    // Make object coherent state === operations ===
    // _size = 0;
    // _buffer = nullptr;

    _buffer = new int[size];
    this -> _size = size;

#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer(unsigned int _size)" << std::endl;
#endif

}

dbuffer::dbuffer(unsigned int size, int value) : _size(0), _buffer(nullptr) {

    // Make object coherent state === operations ===
    // _size = 0;
    // _buffer = nullptr;

    _buffer = new int[size];
    this -> _size = size;

    // IN C++ you can't call another constructor with a constructor
    // Create a private method? A helper method
    for (unsigned int i=0; i<size; ++i) {
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

int dbuffer::getValue(unsigned int index) const {

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

const int &dbuffer::value(unsigned int index) const {

    assert(index < this -> _size);
    return this -> _buffer[index];

}

unsigned int dbuffer::size() const {

    return this -> _size;

}

dbuffer& dbuffer::operator=(const dbuffer &rhs) {

    /// TRUE WAY ///

    if (this != &rhs) {

        dbuffer tmp(rhs); // It fails and it keeps the original in a coherent state

        // Use <algorithm> => swap
        std::swap(this -> _buffer, tmp._buffer); // Swapping content
        std::swap(this -> _size, tmp._size);

        // when going out... tmp automatically

    }


    /// ANOTHER WAY ///
    /*
    // this is the lhs (left hand size)

    // Check if rhs is not this, by using pointers.
    // Check if the addresses are not the same. Avoiding the auto-assignment
    // This is a pointer. also &rhs.
    if (this != &rhs) {

        // If this fails => just exit and the dbuffer state still has its original state...
        // Use temporary variables for taking old data first...
        int *tmp = new int[rhs._size];

        delete[] _buffer;
        _buffer = tmp;
        _size = rhs._size;

        for (unsigned int i = 0; i < _size; ++i) {
            tmp[i] = rhs._buffer[i];
        }

        // Delete old data...
        delete[] _buffer;

        _buffer = tmp;
        _size = rhs._size;

        */

        /// PROBLEMS - MEMORY RECOVERY ///
        /* Not a good way...Because of the coherent state problem...
        delete[] _buffer;
        _buffer = nullptr;
        _size = 0;

        // Simulate a new failure~ without try catch => this is not in a coherent state
        // Add size = 0 then...

        _buffer = new int[rhs._size];
        _size = rhs._size;

        for (unsigned int i = 0; i < _size; ++i) {
            _buffer[i] = rhs._buffer[i];
        }



    } */

    return *this; // I need do de-reference it...

    // Useful for instruction like... a = b =c || a = (b = c) means := put on a the result of b = c

}

dbuffer::dbuffer(const dbuffer &other) : _size(0), _buffer(nullptr) {

    // Make object coherent state === operations ===
    // _size = 0;
    // _buffer = nullptr;

    _buffer = new int[other._size];

    for (unsigned int i = 0; i < other._size; ++i) {
        _buffer[i] = other._buffer[i];
    }

    _size = other._size;

#ifndef NDEBUG
    std::cout << "dbuffer::dbuffer(const dbuffer &other)" << std::endl;
#endif

}
