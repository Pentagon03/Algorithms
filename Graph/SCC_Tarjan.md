# SCC_Tarjan.cpp

This file implements Tarjan's algorithm for finding strongly connected components (SCCs) in a directed graph.

## Usage

*   **Description:** This file implements Tarjan's algorithm for finding strongly connected components (SCCs) in a directed graph.
*   **Structs:**
    *   `scc_graph`
        *   **Description:** A struct that implements Tarjan's algorithm for finding SCCs.
        *   **Members:**
            *   `n`: The number of vertices in the graph.
            *   `pv`: A counter for the DFS discovery time.
            *   `scnt`: The number of strongly connected components.
            *   `called`: A boolean to ensure that the `scc()` function is only called once.
            *   `g`: An adjacency list representing the graph.
            *   `dfsn`: A vector storing the Depth-First Search (DFS) discovery time for each vertex.
            *   `low`: A vector storing the lowest DFS discovery time reachable from each vertex.
            *   `id`: A vector storing the SCC ID for each vertex.
            *   `stk`: A vector used as a stack during DFS.
            *   `in_stk`: A vector indicating whether a vertex is currently in the stack.
        *   **Functions:**
            *   `add_edge(int a, int b)`: Adds a directed edge from vertex a to vertex b.
            *   `scc_id()`: Returns a vector containing the SCC ID for each vertex.
            *   `scc()`: Returns a vector of vectors, where each inner vector stores the vertices belonging to a specific SCC.
            *   `dfs(int x)`: Performs a Depth-First Search (DFS) to compute the discovery times and low-link values.
            *   `reset()`: Resets the state of the graph.