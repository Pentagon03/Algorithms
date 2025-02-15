# crt_coprime.cpp

This file implements the Chinese Remainder Theorem (CRT) for solving a system of congruences where the moduli are pairwise coprime.

## Usage

*   **Description:** This file implements the Chinese Remainder Theorem (CRT) for solving a system of congruences where the moduli are pairwise coprime.
*   **Structs:**
    *   `cong`
        *   **Description:** A struct representing a congruence relation (a mod m).
        *   **Members:**
            *   `a`: The residue.
            *   `m`: The modulus.
        *   **Functions:**
            *   None
*   **Functions:**
    *   `crt(const vector<cong> &cgv)`: Solves a system of congruences using the Chinese Remainder Theorem, assuming that the moduli are pairwise coprime.