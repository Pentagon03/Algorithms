# Fast_LCS.cpp

This file implements an algorithm for finding the Longest Common Subsequence (LCS) of two strings in O(|A|(|B|/|W|)) time complexity, where |W| is the word size (64).

## Usage

*   **Description:** This file implements an algorithm for finding the Longest Common Subsequence (LCS) of two strings using bitset optimization and Hirschberg's algorithm for recovering the LCS.
*   **Namespaces:**
    *   `FAST_LCS`
        *   **Description:** A namespace that encapsulates the fast LCS algorithm.
        *   **Constants:**
            *    `MXN`: max size of string B
            *    `MX_ALP`: number of possible alphabets
            *    `BASE_ALP`: the minimum ascii value among all alphabets
        *   **Members:**
            *   `dt`: An array used in the bitset implementation.
            *   `S`: A 2D array used in the bitset implementation to store the positions of each character in string B.
        *   **Functions:**
            *   `getLCSdp(const string &A,const string &B)`: Calculates the dynamic programming table for LCS using bitset optimization.
            *   `getLCS(const string &A,const string &B)`: Recovers the actual LCS of A and B using Hirschberg's algorithm.