# Data Structure/Compresser.cpp

This file defines a `Compresser` struct for compressing values.

## Compresser Struct

*   **Description:** This file defines a `Compresser` struct that allows you to compress a set of values by mapping them to a smaller range of integers.

*   **Template:**
    *   `Compresser<T>`: A template for compressing values of type `T`.
        ```cpp
        template<class T>
        struct Compresser{
            // ...
        };
        ```
        *   **Parameters:**
            *   `T`: The type of the values to compress.

*   **Struct Members:**
    *   `t`: A vector containing the unique, sorted values.

*   **Functions:**
    *   `Compresser()`: Default constructor.
    *   `Compresser(const vector<T> &v)`: Constructor that initializes the `Compresser` with a vector of values.
    *   `void add(const auto&... x)`: Adds values to the `Compresser`.
    *   `void compress()`: Sorts and removes duplicate values.
    *   `int floor(const T& x) const`: Returns the index of the largest value in `t` that is less than or equal to `x`.
    *   `int ceil(const T& x) const`: Returns the index of the smallest value in `t` that is greater than or equal to `x`.
    *   `int compress(const T& x) const`: Returns the compressed value (index) of `x`.
    *   `void compress(vector<T> &v) const`: Compresses a vector of values.
    *   `const T& val(int i) const`: Returns the original value at index `i`.
    *   `int size() const`: Returns the number of unique values.
