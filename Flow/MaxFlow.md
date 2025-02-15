# MaxFlow.cpp

This file implements the Dinic's algorithm for finding the maximum flow in a network.

## Usage

*   **Description:** This file implements Dinic's algorithm for finding the maximum flow in a network.
*   **Structs:**
    *   `mf_graph<Cap>`
        *   **Description:** A struct that implements Dinic's algorithm for finding the maximum flow in a network.
        *   **Members:**
            *   `n`: The number of vertices in the graph.
            *   `E`: A vector of edges.
            *   `G`: A vector of vectors representing the adjacency list of the graph.
            *   `d`: A vector storing the distance from the source vertex.
            *   `last`: A vector storing the last edge used in the DFS.
        *   **Functions:**
            *   `add_edge(int u, int v, Cap c, bool directed = true)`: Adds an edge from u to v with capacity c.
            *   `flow(int s, int t, Cap flow_limit = cap_inf)`: Finds the maximum flow from s to t with a given flow limit.
            *   `min_cut()`: Returns a vector indicating the vertices reachable from the source in the residual graph after computing the maximum flow.
            *   `get_edge(int i)`: Returns the i-th edge.
            *   `edges()`: Returns all edges in the graph.
            *   `change_edge(int i, Cap new_cap, Cap new_flow, bool directed = true)`: Changes the capacity and flow of the i-th edge.
            *   `reset()`: Resets the flow of all edges to 0.