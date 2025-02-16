# HLD.cpp

This file implements Heavy Light Decomposition (HLD) for trees.

## Usage

*   **Description:** This file implements Heavy Light Decomposition (HLD) for trees, which is a technique used to decompose a tree into paths to efficiently answer path queries.
*   **Functions:**
    *   `dfs_init(int x)`: Initializes the data structures for HLD by performing a Depth-First Search (DFS) to compute subtree sizes and depths.
    *   `dfs_hld(int x)`: Performs a Depth-First Search (DFS) to assign HLD indices and identify heavy paths.
    *   `lca(int x,int y)`: Finds the Lowest Common Ancestor (LCA) of two nodes x and y.
    *   `qry_path(int x,int y,int op)`: Queries the path between nodes x and y.