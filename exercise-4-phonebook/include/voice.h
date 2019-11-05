//
// Created by Nebulino on 11/5/19.
//

#ifndef EXERCISE_4_PHONEBOOK_VOICE_H
#define EXERCISE_4_PHONEBOOK_VOICE_H

#include <string>
#include <ostream>

// class voice with public members
struct voice {

    std::string surname;
    std::string name;
    std::string telephone_number;

    /* TODO: A constructor?
     * if yes, the default constructor will be no-more
     */

    voice();

    voice(  const std::string &s,
            const std::string &n,
            const std::string &tn
            );

};

std::ostream &operator<<(

        std::ostream &ostream,
        const voice &voice

        );

#endif //EXERCISE_4_PHONEBOOK_VOICE_H
