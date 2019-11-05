//
// Created by Nebulino on 11/5/19.
//

#include <algorithm>
#include <cassert>
#include <phonebook.h>


#include "phonebook.h"

phonebook::phonebook() : _size(0), _capacity(0), _voices(nullptr) {};

phonebook::~phonebook() {

    delete[] _voices;
    _size = 0;
    _capacity = 0;
    _voices = nullptr;

}

phonebook::phonebook(size_type capacity) {}

phonebook &phonebook::operator=(const phonebook &other) {

    if (this != &other) {

        phonebook tmp(other);

        std::swap(this -> _size, tmp._size);
        std::swap(this -> _capacity, tmp._capacity);
        std::swap(this -> _voices, tmp._voices);

    }

    return *this;

}

phonebook::phonebook(const phonebook &other) {

    // if this fails, an exception is raised >> new with max capacity
    _voices = new voice[other._capacity];
    _capacity = other._capacity;


    for (size_type i = 0; i < other._size; ++i) {

        _voices[i] = other._voices[i];

    }

    _size = other._size;

}

void phonebook::set_capacity(size_type new_capacity) {

    assert(new_capacity >= 0);

    if (new_capacity > _size) {

        auto *tmp = new voice[new_capacity];

        for (size_type i = 0; i < _size; ++i) {

            tmp[i] = _voices[i];

        }

        _capacity = new_capacity;

        delete[] _voices;
        _voices = tmp;

        /*
         * voices tmp(new_capacity);
         * for (size_type i = 0; i < _size; ++i) {
         *     tmp._voices[i] = _voices[i]
         * }
         */

    }

    // if new_capacity is == _size >> nothing to do
    else if (new_capacity < _size) {

        phonebook tmp(new_capacity);

        std::swap(this -> _size, tmp._size);
        std::swap(this -> _capacity, tmp._capacity);
        std::swap(this -> _voices, tmp._voices);

    }

}

phonebook::size_type phonebook::size() const {

    return _size;

}

phonebook::size_type phonebook::capacity() const {

    return _capacity;

}

voice &phonebook::operator[](size_type index) {

    return _voices[index];

}

const voice &phonebook::operator[](phonebook::size_type index) const {

    return _voices[index];

}

void phonebook::add_voice(const std::string &surname, const std::string &name, const std::string &telephone_number) {

    add_voice(
            voice(surname, name, telephone_number)
            );

}

void phonebook::add_voice(const voice &voice_to_insert) {

    if (_size < _capacity) {

        _voices[_size] = voice_to_insert;
        _size++;

    }

    else {

        // throw "The PhoneBook is full";

        throw phonebook_out_of_space_exception();

    }

}


