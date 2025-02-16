# Hashing.cpp

This file implements a string hashing algorithm using modular arithmetic.

## Usage

*   **Description:** This file implements a string hashing algorithm using modular arithmetic to efficiently compare substrings.
*   **Structs:**
    *   `H`
        *   **Description:** A struct that represents a hash value.
        *   **Members:**
            *   `x`: The hash value.
        *   **Functions:**
            *   Various operator overloads for arithmetic operations (+, -, *).
            *   `get() const`: Returns the hash value.
    *   `HashInterval`
        *   **Description:** A struct that precomputes hash values for all prefixes of a string, allowing for efficient calculation of hash values for any interval.
        *   **Members:**
            *   `ha`: A vector storing the hash values of all prefixes of the string.
            *   `pw`: A vector storing the powers of the hashing constant C.
        *   **Functions:**
            *   `hashInterval(int a, int b)`: Returns the hash value of the substring from index a to b.
*   **Functions:**
    *   `getHashes(string& str, int length)`: Returns a vector of hash values for all substrings of a given length in the string.
    *   `hashString(string& s)`: Returns the hash value of the entire string.