//
// Created by Nebulino on 10/24/19.
//


#include <iostream>
#include <cassert>

#include "dbuffer.h"

void funct1(dbuffer d) {

    std::cout << " === Function 1 === " << std::endl;

}

void funct2(const dbuffer &d) {

    std::cout << " === Function 2 === " << std::endl;
    for (unsigned int i = 0; i < d.size(); ++i) {

        std::cout << "d.value := " << d.value(i) << std::endl;

    }

}

void funct3(dbuffer *d) {

    std::cout << " === Function 3 === " << std::endl;

}


int main(int argc, char *argv[]) {

    /*
     * dbuffer db; // automated initialized when called thanks to the constructor
     *
     * // No new required because is created on the stack
     * dbuffer db2(100);
     * dbuffer db3(10,0);
     */

    dbuffer db[5]; // 5 Constructor and 5 Destructor

    dbuffer db2(100);
    db2.setValue(0, 100);

    int tmp = db2.getValue(0);

    db2.setValue(0, db2.getValue(50));

    // getter and setter in the same instruction
    db2.value(0) = db2.value(50);
    // same as db2._buffer[0] = db2._buffer[50]; // I'm modifying the original

    // tmp = _buffer[0];
    // tmp = db2.db2._buffer[50]; I'm modifying the copy... not the original

    dbuffer db4;
    // assignment:=             db2 => db4
    // not that good tho...the db2 pointer is the same on db4
    // if db2 is being destroyed, db4 array's pointer is also being destroyed
    // So... never use:=        db4 = db2;
    // But use :=               operator=

    db4 = db2;
    assert(db4.size() == db2.size());

    for (unsigned int i = 0; i < db4.size(); ++i) {
        assert(db4.value(i) == db2.value(i));
    }

    // Instead of db4 = 5;
    db4 = dbuffer(5);

    dbuffer db5(5);

    // By passing => copy constructor 2 new 2 destroyers
    funct1(db5);

    // By pointer => pointer data 1 new 1 destroyer
    funct2(db5);

    // By reference => source data 1 new 1 destroyer
    funct3(&db5);

    dbuffer db6(db5);

    return 0;
}