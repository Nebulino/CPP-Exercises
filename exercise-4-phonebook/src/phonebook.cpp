//
// Created by Nebulino on 11/5/19.
//

#include <algorithm>
#include <cassert>
#include <fstream>

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

    assert(index < _size);
    return _voices[index];

}

const voice &phonebook::operator[](phonebook::size_type index) const {

    assert(index < _size);
    return _voices[index];

}

void phonebook::add_voice(const std::string &surname, const std::string &name, const std::string &telephone_number) {

    add_voice(
            voice(surname, name, telephone_number)
            );

}

void phonebook::add_voice(const voice &voice_to_insert) {

    if (_size < _capacity) {

        voice *tmp = nullptr;
        tmp = find_voice_helper(voice_to_insert.telephone_number);

        if (tmp == nullptr) {

            _voices[_size] = voice_to_insert;
            _size++;

        }

        else {

            throw duplicated_voice_exception();
        }

    }

    else {

        // throw "The PhoneBook is full";

        throw phonebook_out_of_space_exception();

    }

}

voice phonebook::find_voice(const std::string &telephone_number) const {

    voice *result = nullptr;
    result = find_voice_helper(telephone_number);

    if (result == nullptr) {

        throw duplicated_voice_exception();

    }

    else {

        return *result;

    }

}

void phonebook::clear() {

    // Is a conceptual clear... so we can't use it on the destroyer
    _size = 0;

}

void phonebook::save(const std::string &filename) const {

    std::ofstream ofstream;

    ofstream.open(filename);

    if (ofstream.is_open()) {

        ofstream << *this;

    }

    else {

        throw file_error_exception();

    }

    ofstream.close();

};

bool phonebook::load(const std::string &filename) const {

    std::ifstream ifstream;

    if (ifstream.is_open()) {

        size_type cap, sz;
        ifstream >> cap;
        ifstream >> sz;

        phonebook tmp;

        // If this fails, this is still untouched
        tmp.set_capacity(cap);

        size_type i;

        for (i = 0; i < sz; ++i) {

            std::string surname, name, phone_number;
            ifstream >> surname;
            ifstream >> name;
            ifstream >> phone_number;

            tmp.add_voice(surname, name, phone_number);

            // We also have add_voice with...
            // voice v(surname, name, phone_number);
            // tmp.add_voice(v);

        }

        std::swap(_voices, tmp._voices);
        std::swap(_size, tmp._size);
        std::swap(_capacity, tmp._capacity);

    }

    else {

        return false;

    }

    ifstream.close();

    return true;

};


voice *phonebook::find_voice_helper(const std::string &telephone_number) const {

    size_type i;

    for (i = 0; i < _size; ++i) {

        if (telephone_number == _voices[i].telephone_number) {

            return &(_voices[i]);
        }

    }

    return nullptr;

}


std::ostream &operator<<(std::ostream &os, const phonebook &pb)  {

    os << pb.capacity() << std::endl;
    os << pb.size() << std::endl;

    for (phonebook::size_type i = 0; i < pb.size(); ++i) {

        os << pb[i];

        if (i < pb.size() -1) {

            os << std::endl;

        }

        // TODO: I want to remove the last endline...

    }

    return os;

};

