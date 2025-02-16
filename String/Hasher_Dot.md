# Hasher_Dot.cpp

This file implements a string hashing algorithm using a simple dot product and unsigned long long integers.

## Usage

*   **Description:** This file implements a string hashing algorithm using a simple dot product and unsigned long long integers.
*   **Structs:**
    *   `Hasher_Dot`
        *   **Description:** A struct that implements the string hashing algorithm.
        *   **Members:**
            *   `sz`: The size of the magic vector.
            *   `magic`: A vector of random unsigned long long integers used for hashing.
            *   `gen`: A Mersenne Twister pseudo-random generator.
        *   **Functions:**
            *   `extend(int n)`: Extends the magic vector to size n.
            *   `hash(const T& s)`: Hashes the given string s.