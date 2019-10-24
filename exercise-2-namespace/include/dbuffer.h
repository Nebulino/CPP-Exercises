//
// Created by Lillie on 10/22/2019.
//

#ifndef ES2_NAMESPACE_DBUFFER_H
#define ES2_NAMESPACE_DBUFFER_H

/**
 *  Namespace: dbuffer
 */
namespace dbuffer {

    /**
     * Struct of dynamic_buffer.
     * @param size : the buffer dimension, in can be small or large, that's why it's better using references
     * @param *buffer : the buffer itself
     */
    struct dynamic_buffer {
        unsigned int size;
        int *buffer;
    };

    /**
     * Function that prints the dynamic buffer in input.
     * @param db
     */
    void dbuffer_print(const dynamic_buffer &db); // Const passage using reference

    /**
     * Function that initialize the dynamic buffer in input.
     * Need to be used once and with a new dbuffer, if not you can occur in memory leaking.
     * @param db : the dynamic buffer
     */
    void initialize_dbuffer(dynamic_buffer &db);

    /**
     * Function that allocate the dynamic buffer in input
     * @param db : the dynamic buffer
     */
    void allocate_dbuffer(dynamic_buffer &db, int dimension=10);

    /**
     * Function that deallocate the dynamic buffer in input
     * @param db : the dynamic buffer
     */
    void deallocate_dbuffer(dynamic_buffer &db);

    /**
     * Function that fill the dynamic buffer by asking or by direct input.
     * @param db : the dynamic buffer
     * @param values : array to use where to take the values
     * @param values_size : the size of the values' array, default is 10 like allocate
     */
    void fill_dbuffer(dynamic_buffer &db, const int *values, int value_size);

    /**
     * Function that copies the dynamic buffer in input into another one.
     * @param db: the dynamic buffer
     * @return : the cloned dynamic buffer
     */
    dynamic_buffer copy_dbuffer(const dynamic_buffer &db);
};


#endif //ES2_NAMESPACE_DBUFFER_H
