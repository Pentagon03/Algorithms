# BCC_Vertex_Disjoint.cpp

This file implements an algorithm for finding vertex-disjoint biconnected components (BCCs) in a graph.

## Usage

*   **Description:** This file implements an algorithm for finding vertex-disjoint biconnected components (BCCs) in a graph.
*   **Namespaces:**
    *   `VertexDisjointBCC`
        *   **Description:** A namespace that encapsulates the vertex-disjoint BCC algorithm.
        *   **Members:**
            *   `g`: An adjacency list representing the graph.
            *   `dfn`: A vector storing the Depth-First Search (DFS) discovery time for each vertex.
            *   `low`: A vector storing the lowest DFS discovery time reachable from each vertex.
            *   `pv`: A counter for the DFS discovery time.
            *   `bcnt`: A counter for the number of BCCs.
            *   `bcc`: A vector storing the BCC assignment for each vertex.
            *   `bridges`: A vector storing the bridges (articulation edges) of the graph.
        *   **Functions:**
            *   `add_edge(int a, int b)`: Adds an undirected edge between vertices a and b.
            *   `dfs(int x, int p = 0)`: Performs a Depth-First Search (DFS) to compute the discovery times and low-link values.
            *   `color(int x, int col)`: Colors the graph to identify the BCCs.
            *   `init(int n)`: Initializes the data structures for a graph with n vertices.
            *   `get_bcc(int n)`: Computes the vertex-disjoint BCCs of the graph.