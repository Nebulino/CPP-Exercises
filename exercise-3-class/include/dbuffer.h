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
    explicit dbuffer(unsigned int size);

    dbuffer(unsigned int size, int value);

    // Default 2: Destructor
    ~dbuffer();

    // Value Getter and Setter
    int getValue(unsigned int index);
    void setValue(unsigned int index, int value);
    int& value(unsigned int index);

    unsigned int size();

    // Default 3: Operator= "Assignment"
    // RightHandSide

    /**
     * Function that copies rhs to himself...
     * @param rhs
     * @return
     */
    dbuffer& operator=(const dbuffer& rhs);


};


#endif //ES3_CLASS_DBUFFER_H
