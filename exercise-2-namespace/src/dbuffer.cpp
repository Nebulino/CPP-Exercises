//
// Created by Lillie on 10/22/2019.
//

#include "dbuffer.h"

#include <iostream>
#include <cassert>

namespace dbuffer {

    void dbuffer_print(const dynamic_buffer &db) {

        assert(db.buffer != nullptr);
        for (int i = 0; i < db.size; ++i) {
            std::cout << db.buffer[i] << " ";
        }

        std::cout << std::endl;

    }

    void initialize_dbuffer(dynamic_buffer &db) {

      // initializing the buffer with a size 0 and a nullptr
      db.size = 0;
      db.buffer = nullptr;

    }

    void allocate_dbuffer(dynamic_buffer &db, unsigned int dimension=10) {

        // If db is already allocated... You'll lose the old values == memory leak...

        // assert(db.buffer == nullptr); // So I'll check it first


        // Another way...
        if (db.buffer != nullptr) {
            /*
             * delete[] db.buffer;
             * initialize_dbuffer(db);
             */

            deallocate_dbuffer(db);
        }

        // Do not change the instructions' order
        db.buffer = new int[db.size];
        db.size = dimension;

        // If not, the status of the buffer can incoherent
        // If the new fails, the old status is preserved

    }

    void deallocate_dbuffer(dynamic_buffer &db) {

        delete[] db.buffer;
        initialize_dbuffer(db);
    }


    void fill_dbuffer(dynamic_buffer &db, const int *values, int, int value_size) {
        assert(values != nullptr);
        assert(db.buffer != nullptr);
        assert(db.size == value_size);

        for (int i = 0; i < db.size; ++i) {

            db.buffer[i] = values[i];

        }
        /*
        std::cout << "You're are going to fill the selected dynamic buffer with " << db.size << std::endl;
        for (int i = 0; i < db.size; ++i) {
            std::cout << "Insert the " << i+1 << "value: ";
            std::cin >> db.buffer[i];
        }
        */

    }


    dynamic_buffer copy_dbuffer(const dynamic_buffer &db) {
        // TODO: Need to fix
        // assert(db.buffer != nullptr && db.size != 0);

        dynamic_buffer cloned_db{};
        initialize_dbuffer(cloned_db);
        fill_dbuffer(cloned_db, db.buffer, db.size);

        return cloned_db;
    }

}
