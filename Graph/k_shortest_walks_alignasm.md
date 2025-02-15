# k_shortest_walks_alignasm.cpp

This file implements an algorithm for finding the k-shortest walks between two nodes in a graph using Eppstein's algorithm, potentially optimized with assembly.

## Usage

*   **Description:** This file implements an algorithm for finding the k-shortest walks between two nodes in a graph using Eppstein's algorithm, potentially optimized with assembly.
*   **Structs:**
    *   `LeftistHeap<Key, Value>`
        *   **Description:** A memory-optimized leftist heap data structure.
        *   **Members:**
            *   `node_rank`: The rank of the node.
            *   `key`: The key of the node.
            *   `value`: The value of the node.
            *   `left`: A pointer to the left child.
            *   `right`: A pointer to the right child.
        *   **Functions:**
            *   `heap_insert(LeftistHeap* a, const Key &k, const Value &v, std::deque<LeftistHeap>&alloc)`: Inserts a new node with key k and value v into the heap.
    *   `kShortestWalksSolver<Distance, WeightedGraph>`
        *   **Description:** A struct that implements the k-shortest walks algorithm.
        *   **Members:**
            *   `MAX_DISTANCE`: A value representing infinity for path length.
            *   `IDENTITY_DISTANCE`: A value representing the identity element for distance calculation (usually 0).
            *   `g`: The weighted graph.
            *   `n`: The number of nodes in the graph.
            *   `is_dag`: A boolean indicating whether the graph is a directed acyclic graph (DAG).
            *   `negative_edge`: A boolean indicating whether the graph contains negative edge weights.
            *   `d`: A vector storing the shortest distances from each node to the sink node.
            *   `best`: A vector storing the best (next) node on the shortest path from each node to the sink node.
            *   `h`: A vector storing pointers to the leftist heaps for each node.
            *   `alloc`: A deque used for memory allocation of the leftist heap nodes.
            *   `distances`: A vector storing the distances of the k-shortest paths.
            *   `path_last_node`: A vector storing the last sidetrack index of each shortest path.
            *   `nodes`: A vector storing the sidetrack pointers.
            *   `prev_node`: A vector storing the previous sidetrack for each sidetrack.
        *   **Functions:**
            *   `kShortestWalksSolver(const WeightedGraph& g_, Distance MAX_DISTANCE_, Distance IDENTITY_DISTANCE_, bool is_dag_ = false, bool negative_edge_ = false)`: Constructor for the kShortestWalksSolver struct.
            *   `dijkstra(const WeightedGraph& g_, int64_t src)`: Runs Dijkstra's algorithm to find the shortest paths from a source node s.
            *   `bellman_ford(const WeightedGraph& g_, int64_t src)`: Runs the Bellman-Ford algorithm to find the shortest paths from a source node s, handling negative edge weights.
            *   `topology_sort(const WeightedGraph& g_)`: Performs a topological sort on a DAG.
            *   `shortest_path_dag(const WeightedGraph& g_, int64_t s)`: Finds the shortest paths from a source node s in a DAG.
            *   `k_shortest_walks(int64_t source, int64_t sink, int64_t k)`: Finds the k shortest walks from the source to the sink.
            *   `kth_shortest_walk_recover(int64_t source, int64_t sink, int64_t k, bool call_k_paths = false)`: Recovers the path of the kth shortest walk.