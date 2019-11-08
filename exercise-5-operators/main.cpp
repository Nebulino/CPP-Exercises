#include <iostream>

/* Operators
 * Unary Operators - 1 Operator
 * !@ -@ @[] *@
 *
 * Binary Operatos - 2 Operators
 * @+@ @=@ << && > <=
 *
 * Can't be re-defined...
 * . & (1 operator - for address)
 *
 * OP= OP[] OP() need to be defined inside the custom value
 * Only inside the class
 *
 */

/// Example Wrapper class...From java to C++
/// Simulate java primitive integer into C++...
/// Not the whole...

/// Integer Class
class Integer {

private:
    int value;

public:

    Integer() : value(0) {}

    Integer &operator=(const Integer &other) {

        value = other.value;
        return *this;

    }

    Integer(const Integer &other) : value(other.value) {}

    /* Not needed... but added to remember
     * ~Integer() {}
     */
    ~Integer() = default;

    // Reading methods...
    int get_value() const {

        // Returns by copy if it's read-only
        return value;

    }

    /* set_value is not needed... because is better using an assignment...
     * object_name.set_value(int_number) => object_name = int_number
     */
    Integer &operator=(int other) {

        value = other;
        return *this;
        /* This Assignment can be updated...
         * like:
         * char -> int
         * double -> int
         * etc...
         */

    }

    Integer &operator=(char other) {

        // Explicit cast... but the compiler can do it without it...
        // Hidden to the user... so sometimes is better doing it explicitly
        value = static_cast<int>(other);
        return *this;

    }

    /* int a + b = c; c is a new value => so return for copy
     * a doesn't change => const
     */
    Integer operator+(const Integer &other) const {

        // return by value because result is going to "die"...
        Integer result;
        // Inside integer class... so I can access directly other.value...
        result.value = this -> value + other.value;

        return result;

    }

    // For c = a - 1
    Integer operator-(int lhs) {

        Integer result;

        result = this -> value - lhs;
        return result;

    }

    /*
     * Strange Unary Operators...
     * i++ ++i --i i--
     *
     * With different syntax because I can't diversify pre and post operator...
     */

    /* Pre-Decrement...
     * => --i
     * We are outside... so the output is the input
     */
    Integer &operator--() {

        // value = value - 1;
        --value;
        return *this;

    }

    /* Post-Decrement...
     * => i--
     * We are outside... so the output is the input created as copy...
     *
     * To differentiate with --i... we put a fake int parameter
     */
    Integer operator--(int) {

        // Copy-constructor...
        Integer tmp = *this;

        // My new re-defined operator--
        --(*this);
        return tmp;
    }

    /* Custom function...
     * Unary Operator
     * For => double f = *c;
     * Source value not changed => const
     */
    double operator*() const {

        return 1.0 / static_cast<double>(value);

    }

    Integer(int i) : value(i) {}

    /* TODO: Integer => int
     * for int i = c
     *
     * No changing state => const
     *
     * Cast-type Operator... A special one...
     * Can be used also with others. char, etc...
     */
    operator int() const {

        return value;

    }
};

/// Globals...

// For c = a + 1
Integer operator+(const Integer &lhs, int rhs) {

    Integer result;

    result = lhs.get_value() + rhs;
    return result;

}

Integer operator-(const Integer &lhs, const Integer &rhs) {

    Integer result;

    result = lhs.get_value() - rhs.get_value();
    return result;

}

Integer operator+(int lhs, const Integer &rhs) {

    Integer result;

    // result = lhs + rhs.get_value();
    // return result;

    // Using the old + operator in the new one...
    result = rhs + lhs;
    return result;

}

bool operator==(const Integer &lhs, const Integer &rhs) {

    // Using the old == operator in the new one...
    return (lhs.get_value() == rhs.get_value());

}

/*
 * Strange Unary Operators...
 * i++ ++i --i i--
 *
 * With different syntax because I can't diversify pre and post operator...
 */

/* Pre-Increment...
 * => ++i
 * We are outside... so the output is the input
 */
Integer &operator++(Integer &i) {

   i = i.get_value() + 1;
   return i;

}

/* Post-Increment...
 * => i--
 * We are outside... so the output is the input created as copy...
 *
 * To differentiate with ++i... we put a fake int parameter
 */
Integer operator++(Integer &i, int) {

    // Copy-constructor...
    Integer tmp = i;

    // My new re-defined operator++
    ++i;
    return tmp;
}


/// Main
int main() {
    std::cout << "Hello, World!" << std::endl;

    // Starting testing the Wrapper
    Integer int_number;

    int_number = 22;
    std::cout << "int_number: " << int_number.get_value() << std::endl;

    Integer a, b, c;

    int i = int_number.get_value();

    c = a + b;
    c = a - b;
    c = a + 1;
    c = a - 1;

    Integer x = 1 + c;

    bool ok = c == b;

    double f = *c; // => 1/c.get_value

    i = c;

    return 0;
}