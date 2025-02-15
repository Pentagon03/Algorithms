# SCC_Kosaraju.cpp

This file implements Kosaraju's algorithm for finding strongly connected components (SCCs) in a directed graph.

## Usage

*   **Description:** This file implements Kosaraju's algorithm for finding strongly connected components (SCCs) in a directed graph.
*   **Structs:**
    *   `scc_graph`
        *   **Description:** A struct that implements Kosaraju's algorithm for finding SCCs.
        *   **Members:**
            *   `n`: The number of vertices in the graph.
            *   `scnt`: The number of strongly connected components.
            *   `called`: A boolean to ensure that the scc() function is only called once.
            *   `g`: An adjacency list representing the graph.
            *   `gR`: An adjacency list representing the reversed graph.
            *   `groups`: A vector of vectors, where each inner vector stores the vertices belonging to a specific SCC.
            *   `vis`: A vector to mark visited vertices during DFS.
            *   `S`: A vector to store vertices in topological order.
            *   `scc_id`: A vector storing the SCC ID for each vertex.
        *   **Functions:**
            *   `add_edge(int a, int b)`: Adds a directed edge from vertex a to vertex b.
            *   `scc()`: Finds the strongly connected components of the graph.
            *   `dfs(int v, bool rev = false)`: Performs a Depth-First Search (DFS) to compute the discovery times and low-link values.