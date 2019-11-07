//
// Created by Nebulino on 11/5/19.
//

#ifndef EXERCISE_4_PHONEBOOK_PHONEBOOK_H
#define EXERCISE_4_PHONEBOOK_PHONEBOOK_H


#include <ostream>

#include "voice.h"


// Exceptions
class phonebook_out_of_space_exception {

    // I need only the name to throw...

};

class duplicated_voice_exception {

};

// PhoneBook Class
class phonebook {

public:
    typedef unsigned int size_type;

private:
    size_type _size;
    voice* _voices;

    size_type _capacity;

    voice *find_voice_helper(const std::string &telephone_number) const;

public:
    phonebook();

    phonebook(size_type capacity);

    ~phonebook();

    phonebook &operator=(const phonebook &other);

    phonebook(const phonebook &other);

    size_type size() const;

    size_type capacity() const;

    void set_capacity(size_type new_capacity);

    voice &operator[](size_type index);

    const voice &operator[](size_type index) const;

    void add_voice(

            // TODO: An assert? An Exception for full Phonebook?

            const std::string &surname,
            const std::string &name,
            const std::string &telephone_number

            );

    void add_voice(const voice &voice_to_insert);

    voice find_voice(const std::string &telephone_number) const;

    void clear();

};


std::ostream &operator<<(std::ostream &os, const phonebook &p);

#endif //EXERCISE_4_PHONEBOOK_PHONEBOOK_H
