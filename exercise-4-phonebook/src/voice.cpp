//
// Created by Nebulino on 11/5/19.
//

#include <voice.h>

#include "voice.h"

voice::voice() {};

voice::voice(
        const std::string &s,
        const std::string &n,
        const std::string &tn) {

    this -> surname = s;
    this -> name = n;
    this -> telephone_number = tn;

}

std::ostream& operator<<(
        std::ostream &os,
        const voice &voice
        ) {

    os << voice.surname << " "    <<
          voice.name    << " "    <<
          voice.telephone_number;

    return os;

}


