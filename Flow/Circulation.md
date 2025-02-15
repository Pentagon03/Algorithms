# Circulation.cpp

This file implements an algorithm for finding a feasible circulation in a network with lower and upper capacity bounds on edges.

## Usage

*   **Description:** This file implements an algorithm for finding a feasible circulation in a network with lower and upper capacity bounds on edges.
*   **Structs:**
    *   `Circulation<Cap>`
        *   **Description:** A struct that implements the circulation algorithm.
        *   **Members:**
            *   `n`: The number of vertices in the graph.
            *   `fg`: An instance of the `mf_graph<Cap>` struct, representing the flow graph.
            *   `demand`: A vector storing the demand at each vertex.
            *   `L`: A vector storing the lower capacity bounds of the edges.
            *   `fsum`: The sum of positive demands.
            *   `s`: The source vertex.
            *   `t`: The sink vertex.
            *   `gs`: A global source vertex.
            *   `gt`: A global sink vertex.
        *   **Functions:**
            *   `add_edge(int u, int v, Cap lower, Cap upper)`: Adds an edge from u to v with lower and upper capacity bounds.
            *   `is_feasible(Cap flow_limit = cap_inf, bool first_call = true, bool exact_flow = false)`: Checks if a feasible circulation exists with the given flow limit from the source to the sink.
            *   `max_flow()`: Returns the maximum flow from the source to the sink.
            *   `min_flow()`: Returns the minimum flow from the source to the sink.
            *   `edges()`: Returns a vector of edges with their corresponding flows.