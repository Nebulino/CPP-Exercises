//
// Created by Nebulino on 10/24/19.
//

#ifndef ES3_CLASS_DBUFFER_H
#define ES3_CLASS_DBUFFER_H

#include <ostream>


class dbuffer {
public:
    // To mask the type... and expose something else...
    typedef unsigned int size_type;

    // All the constructors change the class state

private:
    size_type _size;
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
    explicit dbuffer(size_type size);

    dbuffer(size_type size, int value);

    // Default 2: Destructor
    // Never call the destructor explicitly
    ~dbuffer();

    // Value Getter and Setter

    int getValue(size_type index) const;

    void setValue(size_type index, int value);

    // Not secure for modify stuff...
    int &value(size_type index);
    // Secure one...
    const int &value(size_type index) const;
    // With the same... in the compiler... We can only use the const one...
    // Class Const-ness
    // Also if we use a const method, the utilizer needs to be const as well...


    // This method is not changing the class state => const at the end
    size_type size() const;

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

    void print() const;

    // New [] signature
    // operator[]("" how to index-ize the [] operator input content"")
    // Gonna send an index
    int &operator[](size_type index);

    // const version := read-only
    const int &operator[](size_type index) const;

};


/// New << signature ///
/// GLOBAL ///
// os << db << std::endl;
// << is called stream operator
std::ostream & operator<<(

        // TODO: For a complete serialization, we can give private access...

    // left hand param
    std::ostream &os,
    // right hand param
    const dbuffer &db

);
// std::cout is from ostream...


#endif //ES3_CLASS_DBUFFER_H
