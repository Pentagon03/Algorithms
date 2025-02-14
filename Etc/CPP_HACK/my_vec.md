# Etc/CPP_HACK/my_vec.cpp

This file defines functions for creating and manipulating multi-dimensional vectors in C++.

## Multi-Dimensional Vector Functions

*   **Description:** This file defines a function `vec` that allows you to create multi-dimensional vectors with a specified number of dimensions and an initial value. It also provides functions for appending and adding values to vectors.

*   **Functions:**
    *   `vec(int n, auto&&... s)`: Creates a multi-dimensional vector with size `n` in the first dimension and recursively calls `vec` for the remaining dimensions. The last parameter should be the initial value.
        ```cpp
        auto vec(int n, auto&&... s);
        ```
        *   **Parameters:**
            *   `n`: The size of the first dimension.
            *   `s...`: The sizes for the remaining dimensions, with the last parameter being the initial value.
    *   `append(auto&x, auto&&y)`: Appends the elements of vector `y` to the end of vector `x`.
        ```cpp
        void append(auto&x, auto&&y);
        ```
        *   **Parameters:**
            *   `x`: The vector to append to.
            *   `y`: The vector to append from.
    *   `addv(auto&v, auto&&...x)`: Adds multiple values to the end of vector `v`.
        ```cpp
        void addv(auto&v, auto&&...x);
        ```
        *   **Parameters:**
            *   `v`: The vector to add values to.
            *   `x...`: The values to add.

*   **Usage Examples:**
    ```cpp
    auto V = vec(D1, D2, ... , Initial Value);