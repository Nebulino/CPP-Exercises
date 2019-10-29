//
// Created by Nebulino on 10/24/19.
//

#ifndef ES3_CLASS_DBUFFER_H
#define ES3_CLASS_DBUFFER_H


class dbuffer {

private:
    unsigned int _size;
    int *_buffer;

    // Before public is already private but you can use `private:`
public:

    // Default 1: Constructor definition, called when instantiated
    // Obligatory
    dbuffer();

    // Secondary Constructor
    // One Param constructors can be used as implicit conversion...
    // If I want to create a class with one param... It needs to be explicit... With this keyword...
    // Implicit calls are not permitted... such as
    // db4 = 5; => db4 = dbuffer(5)
    explicit dbuffer(unsigned int size);

    dbuffer(unsigned int size, int value);

    // Default 2: Destructor
    // Never call the destructor explicitly
    ~dbuffer();

    // Value Getter and Setter
    int getValue(unsigned int index);
    void setValue(unsigned int index, int value);
    int& value(unsigned int index);

    unsigned int size();

    // Default 3: Operator= "Assignment"3
    // RightHandSide

    /**
     * Function that copies rhs to himself...
     * @param rhs
     * @return
     */
    dbuffer& operator=(const dbuffer& rhs);

    // Default 4: Copy Constructor

    dbuffer(const dbuffer &other);

};


#endif //ES3_CLASS_DBUFFER_H
