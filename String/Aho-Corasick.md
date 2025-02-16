# Aho-Corasick.cpp

This file implements the Aho-Corasick algorithm for efficient string matching.

## Usage

*   **Description:** This file implements the Aho-Corasick algorithm for efficient string matching, allowing to search for multiple patterns in a text simultaneously.
*   **Structs:**
    *   `Aho_Corasick`
        *   **Description:** A struct that implements the Aho-Corasick algorithm.
        *   **Members:**
            *   `t`: A vector of `Vertex` structs representing the trie.
        *   **Inner Structs:**
            *   `Vertex`
                *   **Description:** A struct representing a node in the trie.
                *   **Members:**
                    *   `next[K]`: An array of integers representing the next nodes for each character in the alphabet.
                    *   `output`: A boolean indicating whether this node represents the end of a pattern.
                    *   `output_len`: The length of the pattern ending at this node.
                    *   `p`: The index of the parent node.
                    *   `pch`: The character that leads to this node from its parent.
                    *   `link`: The suffix link of this node.
                    *   `go[K]`: An array of integers representing the optimized transition function.
                    *   `out_cnt`: The number of patterns that are suffixes of the string represented by this node.
                    *   `pre_out`: The index of the previous node in the suffix link chain that is an output node.
                    *   `max_out_len`: The maximum length of a pattern that is a suffix of the string represented by this node.
        *   **Functions:**
            *   `add_string(string const& s)`: Adds a string to the Aho-Corasick automaton.
            *   `get_link(int v)`: Returns the suffix link of node v.
            *   `go(int v, char ch)`: Returns the node reached by following the character ch from node v.
            *   `get_all_out(int v)`: Returns the number of patterns that are suffixes of the string represented by node v.
            *   `count_occurence(string const&s)`: Counts the number of occurrences of all patterns in the string s.
            *   `chk_included(string const&s, vector<int>&chkv)`: Checks which substrings of s are included in the set of patterns.