# BipartiteMatching.cpp

This file implements an algorithm for finding the maximum bipartite matching in a graph. It also includes functions for finding the minimum vertex cover and maximum independent set.

## Usage

*   **Description:** This file implements an algorithm for finding the maximum bipartite matching in a graph. It also provides functions to find the minimum vertex cover and maximum independent set.
*   **Structs:**
    *   `BipartiteMatching`
        *   **Description:** A struct that implements the bipartite matching algorithm and related functions.
        *   **Members:**
            *   `vis`: A vector to mark visited nodes during DFS.
            *   `A`: A vector to store the matching for group A nodes.
            *   `B`: A vector to store the matching for group B nodes.
            *   `g`: A vector of vectors representing the adjacency list of the graph.
            *   `pv`: A counter used to mark visited nodes during DFS.
        *   **Functions:**
            *   `add_edge(int a, int b)`: Adds an edge between node a in group A and node b in group B.
            *   `max_matching()`: Finds the maximum bipartite matching in the graph.
            *   `get_max_matching()`: Returns a vector of pairs representing the maximum matching.
            *   `get_min_vertex_cover()`: Returns a vector of pairs representing the minimum vertex cover.
            *   `get_max_independent_set()`: Returns a vector of pairs representing the maximum independent set.