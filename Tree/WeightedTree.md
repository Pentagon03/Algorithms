# WeightedTree.cpp

This file implements a weighted tree data structure and related algorithms.

## Usage

*   **Description:** This file implements a weighted tree data structure and related algorithms, such as finding the Lowest Common Ancestor (LCA) and calculating distances between nodes.
*   **Template Parameters:**
    *   `W`: The type of the edge weights.
*   **Structs:**
    *   `WeightedTree`
        *   **Description:** A struct that implements a weighted tree.
        *   **Members:**
            *   `n`: The number of vertices in the tree.
            *   `g`: An adjacency list representing the tree, where each element is a vector of pairs (neighbor, weight).
            *   `in`: A vector storing the in-time of each vertex during DFS.
            *   `out`: A vector storing the out-time of each vertex during DFS.
            *   `dep`: A vector storing the depth of each vertex from the root.
            *   `lg`: The logarithm base 2 of n.
            *   `up`: A 2D vector storing the ancestors of each vertex at different powers of 2.
        *   **Functions:**
            *   `add_edge(int a, int b, W w = 1)`: Adds an edge between vertices a and b with weight w.
            *   `init(int root)`: Initializes the data structures for the tree by performing a Depth-First Search (DFS) starting from the given root.
            *   `dfs(int x,int p)`: Performs a Depth-First Search (DFS) to compute the in-times, out-times, depths, and ancestors of each vertex.
            *   `go_up(int x,int cnt)`: Returns the ancestor of vertex x that is cnt levels above x.
            *   `is_ancestor(int u, int v)`: Checks if vertex u is an ancestor of vertex v.
            *   `lca(int u,int v)`: Finds the Lowest Common Ancestor (LCA) of vertices u and v.
            *   `tree_dist(int u,int v)`: Calculates the distance between vertices u and v in the tree.
            *   `on_ancestor_path(int u, int p, int x)`: Checks if vertex x lies on the path from vertex u to its ancestor p.
            *   `on_path(int u,int v,int x)`: Checks if vertex x lies on the path between vertices u and v.
            *   `tree_mid(int u, int v)`: Finds the midpoint of the path between vertices u and v (only when all edge weights are 1).