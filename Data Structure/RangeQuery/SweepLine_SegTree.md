# Data Structure/RangeQuery/SweepLine_SegTree.cpp

This file contains a struct. You need to create an object of the struct to use it.

## SweepLine (Segment Tree)

```cpp
template<class T>
struct SweepLine{
    const vector<T>& c;
    unsigned n;
    struct Node{
        int cover;
        T sum;
    };
    vector<Node> tree;
    SweepLine(const vector<T>& compressed);
    void upd(int l, int r, int x, int nd = 1, int s = 0, int e = -1);
    int qry_all();
    int qry(int l, int r, int nd = 1, int s = 0, int e = -1);
};
```

*   **Description:** A struct for implementing a Sweep Line algorithm using a Segment Tree.
*   **Template Parameters:**
    *   `T`: The type of the compressed coordinates.
*   **Usage:** Create an object of the `SweepLine` struct and then call the member functions.

*   **Functions:**
    *   `SweepLine(const vector<T>& compressed)`: Constructor that initializes the SweepLine structure with compressed coordinates.
        ```cpp
        SweepLine(const vector<T>& compressed);
        ```
        *   **Parameters:**
            *   `compressed`: A vector of compressed coordinates.
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
    *   `int qry_all()`: Queries the entire range and returns the sum.
        ```cpp
        int qry_all();
        ```
        *   **Returns:** The sum of the entire range.
    *   `int qry(int l, int r, int nd = 1, int s = 0, int e = -1)`: Queries the range `[l, r)` and returns the sum.
        ```cpp
        int qry(int l, int r, int nd = 1, int s = 0, int e = -1);
        ```
        *   **Parameters:**
            *   `l`: The left boundary of the range.
            *   `r`: The right boundary of the range.
            *   `nd`: The current node index (default: 1).
            *   `s`: The start of the current range (default: 0).
            *   `e`: The end of the current range (default: -1, which means `n`).
        *   **Returns:** The sum of the range `[l, r)`.