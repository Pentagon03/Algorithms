# Suffix_Array_Benq.cpp

This file implements the suffix array and LCP (Longest Common Prefix) array algorithms, based on the implementation by Benq.

## SuffixArray Struct

*   **Description:** This file defines a `SuffixArray` struct that implements the suffix array and LCP array algorithms.

*   **Struct Members:**
    *   `S`: The input string for which the suffix array is constructed.
    *   `N`: The length of the input string plus 1.
    *   `sa`: The suffix array, where `sa[i]` is the starting index of the i-th lexicographically smallest suffix of S.
    *   `isa`: The inverse suffix array, where `isa[i]` is the index of the suffix S[i:] in the suffix array.
    *   `lcp`: The LCP array, where `lcp[i]` is the length of the longest common prefix between the suffixes S[sa[i]:] and S[sa[i+1]:].

*   **Functions:**
    *   `SuffixArray(const str& _S)`: Constructor that takes the input string S and constructs the suffix array and LCP array.
    *   `genSa()`: Generates the suffix array `sa`.
    *   `genLcp()`: Generates the LCP array `lcp` using Kasai's algorithm.