#include <iostream>
#include "dbuffer.h"


int main() {

    /*
    // Testing...
    int tmp[] = {0, 1, 2, 3, 4};

    // Create a new dynamic buffer
    dbuffer::dynamic_buffer db{};
    dbuffer::initialize_dbuffer(db);
    db.buffer = tmp;
    db.size = 5;

    // Print Testing
    dbuffer::dbuffer_print(db);

    dbuffer::deallocate_dbuffer(db);
    */

    dbuffer::dynamic_buffer db{};
    dbuffer::initialize_dbuffer(db);

    // size = 10 is default
    dbuffer::allocate_dbuffer(db, 10);

    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    dbuffer::fill_dbuffer(db, data, 10);

    dbuffer::dbuffer_print(db);

    dbuffer::deallocate_dbuffer(db);

}