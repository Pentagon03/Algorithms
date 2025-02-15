# WeightedGraph.cpp

This file implements a weighted graph data structure and related algorithms.

## Usage

*   **Description:** This file implements a weighted graph data structure and related algorithms, including Dijkstra's algorithm, Bellman-Ford algorithm, and Floyd-Warshall algorithm.
*   **Structs:**
    *   `WeightedGraph<W>`
        *   **Description:** A struct that implements a weighted graph.
        *   **Members:**
            *   `n`: The number of vertices in the graph.
            *   `g`: An adjacency list representing the graph, where each element is a vector of pairs (neighbor, weight).
        *   **Functions:**
            *   `add_edge(int a, int b, W w = 1, bool directed = true)`: Adds an edge from vertex a to vertex b with weight w.
            *   `dijkstra(int src, int max_step = -1, W INF = INF_)`: Runs Dijkstra's algorithm to find the shortest paths from a source node s.
            *   `bellman_ford(int src, bool &neg_cycle, int max_step = -1, W INF = INF_)`: Runs the Bellman-Ford algorithm to find the shortest paths from a source node s, handling negative edge weights.
            *   `topological_sort()`: Performs a topological sort on a DAG.
            *   `dag_shortest_path(int src, W INF = INF_)`: Finds the shortest paths from a source node s in a DAG.
            *   `find_path(int src, int dest, const vector<int>& dis, const vector<int>& d)`: Reconstructs the shortest path from src to dest given the distance and predecessor vectors.
            *   `floyd_warshall(bool &neg_cycle, int max_node = -1, W INF = INF_)`: Runs the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices.
            *   `find_path_floyd_warshall(int from, int to, const vector<vector<int>>& d)`: Reconstructs the shortest path from from to to given the predecessor matrix computed by Floyd-Warshall.