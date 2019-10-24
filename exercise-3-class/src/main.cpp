//
// Created by Nebulino on 10/24/19.
//


#include <iostream>
#include "dbuffer.h"

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

    return 0;
}