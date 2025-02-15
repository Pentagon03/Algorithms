# KPATH_INDEX_VERSION.cpp

This file implements an algorithm for finding the k-shortest paths between two nodes in a graph, using a memory-optimized leftist heap and an index-based approach.

## Usage

*   **Description:** This file implements an algorithm for finding the k-shortest paths between two nodes in a graph, using a memory-optimized leftist heap and an index-based approach.
*   **Structs:**
    *   `LeftistHeap<Key, Value>`
        *   **Description:** A memory-optimized leftist heap data structure.
        *   **Members:**
            *   `node_rank`: The rank of the node.
            *   `key`: The key of the node.
            *   `value`: The value of the node.
            *   `left`: The index of the left child.
            *   `right`: The index of the right child.
        *   **Functions:**
            *   `emplace(int rank_, Key key_, Value value_, int left_, int right_, std::vector<LeftistHeap>& alloc, int &pivot)`: Creates a new node in the heap.
            *   `heap_insert(int a, const Key k, const Value v, std::vector<LeftistHeap>& alloc, int &pivot)`: Inserts a new node with key k and value v into the heap.
    *   `K_Shortest_Paths_Solver<Distance, WeightedGraph>`
        *   **Description:** A struct that implements the k-shortest paths algorithm.
        *   **Members:**
            *   `MAX_DISTANCE`: A value representing infinity for path length.
            *   `BASE_DISTANCE`: A base distance value.
            *   `g`: The weighted graph.
            *   `n`: The number of nodes in the graph.
            *   `is_dag`: A boolean indicating whether the graph is a directed acyclic graph (DAG).
            *   `d`: A vector storing the shortest distances from the sink to all other nodes.
            *   `best`: A vector storing the best (previous) node on the shortest path from each node to the sink.
            *   `alloc`: A vector used for memory allocation of the leftist heap nodes.
            *   `pivot`: An index used for memory allocation of the leftist heap nodes.
            *   `h`: A vector storing the indices of the leftist heaps for each node.
            *   `distances`: A vector storing the distances of the k-shortest paths.
            *   `path_nodes`: A vector storing the last sidetrack index of each shortest path.
            *   `nodes`: A vector storing the nodes in the heap.
            *   `prev_node`: A vector storing the previous node for each node in the heap.
        *   **Functions:**
            *   `dijkstra(const WeightedGraph& g_, int s)`: Runs Dijkstra's algorithm to find the shortest paths from a source node s.
            *   `topology_sort(const WeightedGraph& g_)`: Performs a topological sort on a DAG.
            *   `shortest_path_dag(const WeightedGraph& g_, int s)`: Finds the shortest paths from a source node s in a DAG.
            *   `k_shortest_paths(int source, int sink, int k)`: Finds the k shortest paths from the source to the sink.
            *   `kth_shortest_full_path(int source, int sink, int k, bool call_k_paths = false)`: Returns the full path of the kth shortest path.