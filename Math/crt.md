# crt.cpp

This file implements the Chinese Remainder Theorem (CRT) for solving a system of congruences.

## Usage

*   **Description:** This file implements the Chinese Remainder Theorem (CRT) for solving a system of congruences, handling all cases (not just pairwise coprime moduli).
*   **Structs:**
    *   `cong`
        *   **Description:** A struct representing a congruence relation (a mod m).
        *   **Members:**
            *   `a`: The residue.
            *   `m`: The modulus.
        *   **Functions:**
            *   None
*   **Functions:**
    *   `crt_merge(const cong &c1, const cong &c2)`: Merges two congruence relations into a single congruence relation.
    *   `crt(const vector<cong> &cgv)`: Solves a system of congruences using the Chinese Remainder Theorem.