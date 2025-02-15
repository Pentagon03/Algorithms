# MinCostFlow.cpp

This file implements the Minimum Cost Flow algorithm using the SPFA (Shortest Path Faster Algorithm) or Dijkstra's algorithm for finding shortest paths.

## Usage

*   **Description:** This file implements the Minimum Cost Flow algorithm, which finds the cheapest way to transport a certain amount of flow through a network.
*   **Structs:**
    *   `mcf_graph<Cap, Cost>`
        *   **Description:** A struct that implements the Minimum Cost Flow algorithm.
        *   **Members:**
            *   `n`: The number of vertices in the graph.
            *   `E`: A vector of edges.
            *   `G`: A vector of vectors representing the adjacency list of the graph.
            *   `d`: A vector storing the distance from the source vertex.
            *   `vis`: A vector to mark visited vertices during SPFA.
            *   `last`: A vector storing the last edge used in the DFS.
        *   **Functions:**
            *   `add_edge(int u, int v, Cap cap, Cost cost, bool directed = true)`: Adds an edge from u to v with capacity cap and cost cost.
            *   `slope(int s, int t, Cap flow_limit = cap_inf, Cost cost_limit = cost_inf - 1, int paths_limit = paths_inf)`: Finds the minimum cost flow from s to t and returns a vector of (flow, cost) pairs representing the convex piecewise linear function of the flow and cost.
            *   `flow(int s, int t, Cap flow_limit = cap_inf, Cost cost_limit = cost_inf - 1, int paths_limit = paths_inf)`: Finds the minimum cost flow from s to t with a given flow limit and cost limit.
            *   `min_cut()`: Returns a vector indicating the vertices reachable from the source in the residual graph after computing the minimum cost flow.
            *   `get_edge(int i)`: Returns the i-th edge.
            *   `edges()`: Returns all edges in the graph.
            *   `change_edge(int i, Cap new_cap, Cap new_flow, Cost new_cost)`: Changes the capacity, flow and cost of the i-th edge.
            *   `reset()`: Resets the flow of all edges to 0.