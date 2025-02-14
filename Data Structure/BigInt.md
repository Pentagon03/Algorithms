# Data Structure/BigInt.cpp

This file defines a `BigInt` struct for handling arbitrarily large integers.

## BigInt Struct

*   **Description:** This file defines a `BigInt` struct that allows you to perform arithmetic operations on integers that exceed the limits of standard integer types.

*   **Constants:**
    *   `BASE_DIGITS`: The number of digits in each base unit (default: 9).
    *   `BASE`: The base for representing the large integer (default: 1000000000).

*   **Struct Members:**
    *   `sign`: An integer representing the sign of the number (1 for positive, -1 for negative).
    *   `a`: A vector of integers representing the digits of the number in base `BASE`.

*   **Constructors:**
    *   `BigInt()`: Default constructor, initializes to 0.
    *   `BigInt(long long v)`: Constructor from a `long long` integer.
    *   `BigInt(const string& s)`: Constructor from a string representation of an integer.

*   **Input/Output:**
    *   `read(const string& s)`: Reads a `BigInt` from a string.
    *   `friend istream& operator>>(istream &stream, BigInt &v)`: Overloads the input stream operator to read a `BigInt`.
    *   `friend ostream& operator<<(ostream &stream, const BigInt &v)`: Overloads the output stream operator to print a `BigInt`.

*   **Comparison Operators:**
    *   `bool operator<(const BigInt &v) const`: Less than operator.
    *   `bool operator>(const BigInt &v) const`: Greater than operator.
    *   `bool operator<=(const BigInt &v) const`: Less than or equal to operator.
    *   `bool operator>=(const BigInt &v) const`: Greater than or equal to operator.
    *   `bool operator==(const BigInt &v) const`: Equal to operator.
    *   `bool operator!=(const BigInt &v) const`: Not equal to operator.

*   **Arithmetic Operators:**
    *   `BigInt operator-() const`: Unary minus operator.
    *   `BigInt operator += (const BigInt& v)`: Addition assignment operator.
    *   `BigInt operator -= (const BigInt& v)`: Subtraction assignment operator.
    *   `friend BigInt operator + (L&& l, R&& r)`: Addition operator.
    *   `friend BigInt operator - (L&& l, R&& r)`: Subtraction operator.
    *   `friend pair<BigInt, BigInt> divmod(const BigInt& a1, const BigInt& b1)`: Returns the quotient and remainder of the division.
    *   `BigInt operator/(const BigInt &v) const`: Division operator.
    *   `BigInt operator%(const BigInt &v) const`: Modulo operator.
    *   `void operator/=(int v)`: Division assignment operator with an integer.
    *   `BigInt operator/(int v) const`: Division operator with an integer.
    *   `void operator/=(const BigInt &v)`: Division assignment operator.
    *   `long long operator%(long long v) const`: Modulo operator with a `long long` integer.
    *   `void operator*=(int v)`: Multiplication assignment operator with an integer.
    *   `BigInt operator*(int v) const`: Multiplication operator with an integer.
    *   `void operator*=(const BigInt &v)`: Multiplication assignment operator.
    *   `BigInt operator*(const BigInt &v) const`: Multiplication operator.

*   **Other Functions:**
    *   `BigInt abs() const`: Returns the absolute value of the `BigInt`.
    *   `void trim()`: Removes leading zeros.
    *   `bool isZero() const`: Checks if the `BigInt` is zero.
    *   `friend BigInt gcd(const BigInt &x, const BigInt &y)`: Calculates the greatest common divisor.
    *   `friend BigInt lcm(const BigInt &x, const BigInt &y)`: Calculates the least common multiple.
    *   `friend BigInt sqrt(const BigInt &a1)`: Calculates the square root.
