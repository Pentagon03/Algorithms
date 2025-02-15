# k_shortest_walks.cpp

This file implements an algorithm for finding the k-shortest walks between two nodes in a graph using Eppstein's algorithm.

## Usage

*   **Description:** This file implements an algorithm for finding the k-shortest walks between two nodes in a graph using Eppstein's algorithm.
*   **Structs:**
    *   `kShortestWalksSolver<WeightedGraph, Distance>`
        *   **Description:** A struct that implements the k-shortest walks algorithm.
        *   **Members:**
            *   `g`: The weighted graph.
            *   `n`: The number of nodes in the graph.
            *   `MAX_DISTANCE`: A value representing infinity for path length.
            *   `IDENTITY_DISTANCE`: A value representing the identity element for distance calculation (usually 0).
            *   `is_dag`: A boolean indicating whether the graph is a directed acyclic graph (DAG).
            *   `negative_edge`: A boolean indicating whether the graph contains negative edge weights.
            *   `d`: A vector storing the shortest distances from each node to the sink node.
            *   `best`: A vector storing the next node on the shortest path from each node to the sink node.
            *   `alloc`: A deque used for memory allocation of the leftist heap nodes.
            *   `h`: A vector storing pointers to the leftist heaps for each node.
            *   `distances`: A vector storing the distances of the k-shortest paths.
            *   `path_last_node`: A vector storing the last sidetrack index of each shortest path.
            *   `nodes`: A vector storing the sidetrack pointers.
            *   `prev_node`: A vector storing the previous sidetrack for each sidetrack.
        *   **Functions:**
            *   `kShortestWalksSolver(const WeightedGraph& g_, Distance MAX_DISTANCE_, Distance IDENTITY_DISTANCE_, bool is_dag_ = false, bool negative_edge_ = false)`: Constructor for the kShortestWalksSolver struct.
            *   `k_shortest_walks(int source, int sink, int k)`: Finds the k shortest walks from the source to the sink.
            *   `kth_shortest_walk_recover(int source, int sink, int k, bool call_k_paths = false)`: Recovers the path of the kth shortest walk.
            *   `dijkstra(const WeightedGraph& g_, int src)`: Runs Dijkstra's algorithm to find the shortest paths from a source node s.
            *   `bellman_ford(const WeightedGraph& g_, int src)`: Runs the Bellman-Ford algorithm to find the shortest paths from a source node s, handling negative edge weights.
            *   `topology_sort(const WeightedGraph& g_)`: Performs a topological sort on a DAG.
            *   `shortest_path_dag(const WeightedGraph& g_, int s)`: Finds the shortest paths from a source node s in a DAG.