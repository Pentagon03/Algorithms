# Etc/CPP_HACK/constants.cpp

This file defines some commonly used constants in C++.

## Constants

*   **Description:** This file defines constants such as PI, E, and INF for use in C++ programs.

*   **Constants:**
    *   `PI<T>`: Defines the constant PI with a specified type `T` (default: `long double`).
        ```cpp
        template<typename T = long double> constexpr T PI = numbers::pi_v<T>;
        ```
    *   `E<T>`: Defines the constant E (Euler's number) with a specified type `T` (default: `long double`).
        ```cpp
        template<typename T = long double> constexpr T E = numbers::e_v<T>;
        ```
    *   `INF<T>`: Defines a large value representing infinity with a specified type `T` (default: `int`).
        ```cpp
        template<typename T = int> constexpr T INF = infinity<T>::max;
        ```
        *   The `infinity` struct is used to calculate a large value based on the maximum representable value for the given type.