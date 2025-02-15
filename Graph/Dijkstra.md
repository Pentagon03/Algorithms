# Dijkstra.cpp

This file implements Dijkstra's algorithm for finding the shortest paths from a source node to all other nodes in a weighted graph.

## Usage

*   **Description:** This file implements Dijkstra's algorithm for finding the shortest paths from a source node to all other nodes in a weighted graph.
*   **Functions:**
    *   `dijkstra(int src, T INF, const Graph& g)`
        *   **Description:** Finds the shortest paths from a source node to all other nodes in a weighted graph using Dijkstra's algorithm.
        *   **Args:**
            *   `src (int)`: The source node.
            *   `INF (T)`: A value representing infinity.
            *   `g (const Graph&)`: The graph represented as an adjacency list.
        *   **Returns:**
            *   `vector<T>`: A vector containing the shortest distances from the source node to all other nodes.