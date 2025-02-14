# Data Structure/DisjointSet.cpp

This file defines a `DisjointSet` struct for managing disjoint sets.

## DisjointSet Struct

*   **Description:** This file defines a `DisjointSet` struct that allows you to manage disjoint sets, also known as union-find data structure.

*   **Struct Members:**
    *   `n`: The number of elements.
    *   `par`: A vector representing the parent of each element. If `par[u]` is negative, then `u` is the leader of the set and `-par[u]` is the size of the set.

*   **Functions:**
    *   `DisjointSet(int _n = 0)`: Constructor that initializes the `DisjointSet` with `_n` elements.
    *   `void make_leader(int u)`: Makes `u` the leader of its own set.
    *   `int leader(int u)`: Finds the leader of the set containing element `u` with path compression.
    *   `bool merge(int u, int v)`: Merges the sets containing elements `u` and `v`. Returns `true` if the sets were merged, `false` otherwise.
    *   `bool same(int u, int v)`: Checks if elements `u` and `v` are in the same set.
    *   `int leader_size(int u)`: Returns the size of the set that `u` is the leader of.
    *   `int size(int u)`: Returns the size of the set containing element `u`.
    *   `vector<vector<int>> groups()`: Returns a vector of vectors, where each inner vector contains the elements in a disjoint set.
