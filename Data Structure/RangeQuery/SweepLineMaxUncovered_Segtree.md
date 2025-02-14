# Data Structure/RangeQuery/SweepLineMaxUncovered_Segtree.cpp

This file contains a struct. You need to create an object of the struct to use it.

## SweepLineMaxUncovered (Segment Tree)

```cpp
template<typename T>
struct SweepLineMaxUncovered{
    int n;
    struct Node{
        int cover;
        T len, mx, lmx, rmx;
        void init(bool covered);
        friend Node operator +(Node a, Node b);
    };
    static constexpr Node enode = Node{0, 0, 0, 0, 0};
    vector<Node> tree;
    SweepLineMaxUncovered(int n);
    SweepLineMaxUncovered(const vector<T>& compressed);
    void build(const vector<T> & c, int nd = 1, int s = 0, int e = -1);
    void upd(int l, int r, int x, int nd = 1, int s = 0, int e = -1);
    Node qry_all();
    Node qry(int l, int r, int nd = 1, int s = 0, int e = -1);
};
```

*   **Description:** A struct for implementing a Sweep Line algorithm to find the maximum uncovered length using a Segment Tree.
*   **Template Parameters:**
    *   `T`: The type of the coordinates.
*   **Usage:** Create an object of the `SweepLineMaxUncovered` struct and then call the member functions.

*   **Functions:**
    *   `SweepLineMaxUncovered(int n)`: Constructor that initializes the structure with a range `[0, n)`.
        ```cpp
        SweepLineMaxUncovered(int n);
        ```
        *   **Parameters:**
            *   `n`: The size of the range.
    *   `SweepLineMaxUncovered(const vector<T>& compressed)`: Constructor that initializes the structure with compressed coordinates.
        ```cpp
        SweepLineMaxUncovered(const vector<T>& compressed);
        ```
        *   **Parameters:**
            *   `compressed`: A vector of compressed coordinates.
    *   `void build(const vector<T> & c, int nd = 1, int s = 0, int e = -1)`: Builds the segment tree.
        ```cpp
        void build(const vector<T> & c, int nd = 1, int s = 0, int e = -1);
        ```
        *   **Parameters:**
            *   `c`: The vector of compressed coordinates.
            *   `nd`: The current node index (default: 1).
            *   `s`: The start of the current range (default: 0).
            *   `e`: The end of the current range (default: -1, which means `n`).
    *   `void upd(int l, int r, int x, int nd = 1, int s = 0, int e = -1)`: Updates the range `[l, r)` by adding `x` to the cover value.
        ```cpp
        void upd(int l, int r, int x, int nd = 1, int s = 0, int e = -1);
        ```
        *   **Parameters:**
            *   `l`: The left boundary of the range.
            *   `r`: The right boundary of the range.
            *   `x`: The value to add to the cover.
            *   `nd`: The current node index (default: 1).
            *   `s`: The start of the current range (default: 0).
            *   `e`: The end of the current range (default: -1, which means `n`).
    *   `Node qry_all()`: Queries the entire range and returns the root node.
        ```cpp
        Node qry_all();
        ```
        *   **Returns:** The root node of the segment tree.
    *   `Node qry(int l, int r, int nd = 1, int s = 0, int e = -1)`: Queries the range `[l, r)` and returns the result node.
        ```cpp
        Node qry(int l, int r, int nd = 1, int s = 0, int e = -1);
        ```
        *   **Parameters:**
            *   `l`: The left boundary of the range.
            *   `r`: The right boundary of the range.
            *   `nd`: The current node index (default: 1).
            *   `s`: The start of the current range (default: 0).
            *   `e`: The end of the current range (default: -1, which means `n`).
        *   **Returns:** The result node for the range `[l, r)`.