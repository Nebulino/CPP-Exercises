//
// Created by Nebulino on 10/31/2019.
//

#include <iostream>
#include <cassert>
#include <fstream>

#include "dbuffer.h"


void useful_tests() {

    /// CONSTRUCTIORS TESTS ///
    dbuffer db1;
    assert(db1.size() == 0);

    dbuffer db2(100);
    assert(db2.size() == 100);

    dbuffer db3(50, -1);
    assert(db3.size() == 50);
    for (dbuffer::size_type i = 0; i < 50; ++i) {
        assert(db3[i] == -1);
    }

    dbuffer db4(db3);
    // It's a copy-constructor, not an assignment
    // Assignment is without init...
    assert(db4.size() == db3.size());
    for (dbuffer::size_type i = 0; i < 50; ++i) {
        assert(db3[i] == db4[i]);
    }

    // Assignment Operator
    db1 = db3;
    assert(db1.size() == db3.size());
    for (dbuffer::size_type i = 0; i < 50; ++i) {
        assert(db3[i] == db1[i]);
    }

}

void test_buffer() {

    dbuffer db(5, 0);

    for (dbuffer::size_type i = 0; i < 5; ++i) {
        db[i] = i;
        // assert
    }

    db4[4] = 100;
    // assert

    db[3] = db[4];
    // assert

    // int tmp = db[8];

    int tmp = db[3];

    std::cout << db4 << std::endl;

}

void test_dbuffer_const_helper(const dbuffer &db) {

    for (dbuffer::size_type i = 0; i < ; ++i) {

    }

}

void test_dbuffer_const() {

    dbuffer db(5, 0);

    test_dbuffer_const_helper(db);

}
