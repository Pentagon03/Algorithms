# Data Structure/RangeQuery/LiChaoTree_Rollback.cpp

This file contains a struct. You need to create an object of the struct to use it.

## Li_Chao (Rollback)

```cpp
struct Li_Chao{
    vector<Node> tree;
    void init(ll s, ll e);
    void update(int node, Line v, int now);
    ll query(int node, ll x);
    void rb(int now);
} seg;
```

*   **Description:** A struct for implementing a Rollback Li Chao Tree.
*   **Usage:** Create an object of the `Li_Chao` struct and then call the member functions.

*   **Functions:**
    *   `void init(ll s, ll e)`: Initializes the Li Chao Tree with range `[s, e]`.
        ```cpp
        void init(ll s, ll e);
        ```
        *   **Parameters:**
            *   `s`: The start of the range.
            *   `e`: The end of the range.
    *   `void update(int node, Line v, int now)`: Updates the Li Chao Tree with a line `v` at the given node.
        ```cpp
        void update(int node, Line v, int now);
        ```
        *   **Parameters:**
            *   `node`: The node to update.
            *   `v`: The line to insert, represented as a `Line` struct (m*x + y).
            *   `now`: The current rollback point.
    *   `ll query(int node, ll x)`: Queries the minimum value at point `x` in the Li Chao Tree.
        ```cpp
        ll query(int node, ll x);
        ```
        *   **Parameters:**
            *   `node`: The node to query.
            *   `x`: The x-coordinate to query.
        *   **Returns:** The minimum value among all lines at point `x`.
    *   `void rb(int now)`: Rolls back the Li Chao Tree to a previous state.
        ```cpp
        void rb(int now);
        ```
        *   **Parameters:**
            *   `now`: The rollback point to revert to.