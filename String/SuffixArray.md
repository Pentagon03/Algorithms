# SuffixArray.cpp

This file implements the suffix array and LCP (Longest Common Prefix) array construction algorithms.

## Usage

*   **Description:** This file implements the suffix array and LCP (Longest Common Prefix) array construction algorithms.
*   **Functions:**
    *   `sort_cyclic_shifts(string const& s)`: Sorts cyclic shifts of the string s.
    *   `suffix_array_construction(string s)`: Constructs the suffix array for the given string s.
    *   `lcp_construction(string const& s, vector<int> const& p)`: Constructs the LCP array for the given string s and its suffix array p.
    *   `lcp_construction(string const& s)`: Constructs the LCP array for the given string s (overloaded function).