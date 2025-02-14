# Data Structure/RangeQuery/MergeSortTree.cpp

This file contains a struct. You need to create an object of the struct to use it.

## MergeSortTree

```cpp
template<typename T = int>
struct MergeSortTree{
    using Vec = vector<T>;
    int n, base;
    vector<Vec> tree;
    MergeSortTree(){}
    MergeSortTree(const Vec& v);
    int elem(int k);
    int cnt_qry(int l,int r,const function<int(const Vec&)>& op);
    int rightmost(int l, int k, const function<int(const Vec&)>& op);
    int leftmost(int r, int k, const function<int(const Vec&)>& op);
    static inline int greater(const Vec&v, int x);
    static inline int less(const Vec&v, int x);
    static inline int greater_equal(const Vec&v, int x);
    static inline int less_equal(const Vec&v,  int x);
    static inline int in_range(const Vec&v,  int x, int y);
    static inline int equal(const Vec&v, int x);
};
```

*   **Description:** A struct for implementing a Merge Sort Tree.
*   **Template Parameters:**
    *   `T`: The type of the elements in the tree (default: `int`).
*   **Usage:** Create an object of the `MergeSortTree` struct and then call the member functions.

*   **Functions:**
    *   `MergeSortTree(const Vec& v)`: Constructor that builds the tree from a given vector.
        ```cpp
        MergeSortTree(const Vec& v);
        ```
        *   **Parameters:**
            *   `v`: The input vector.
    *   `int elem(int k)`: Returns the k-th element of the original vector.
        ```cpp
        int elem(int k);
        ```
        *   **Parameters:**
            *   `k`: The index of the element to retrieve.
        *   **Returns:** The value of the k-th element.
    *   `int cnt_qry(int l,int r,const function<int(const Vec&)>& op)`: Counts elements in range `[l, r]` that satisfy a given condition.
        ```cpp
        int cnt_qry(int l,int r,const function<int(const Vec&)>& op);
        ```
        *   **Parameters:**
            *   `l`: The left boundary of the range.
            *   `r`: The right boundary of the range.
            *   `op`: A function that takes a vector and returns an integer (e.g., counts elements less than a value).
        *   **Returns:** The count of elements satisfying the condition.
    *   `int rightmost(int l, int k, const function<int(const Vec&)>& op)`: Finds the rightmost index `t` such that `op([l, t]) <= k`.
    *   `int leftmost(int r, int k, const function<int(const Vec&)>& op)`: Finds the leftmost index `t` such that `op([t, r]) <= k`.
    *   `static inline int greater(const Vec&v, int x)`: Counts elements in `v` greater than `x`.
    *   `static inline int less(const Vec&v, int x)`: Counts elements in `v` less than `x`.
    *   `static inline int greater_equal(const Vec&v, int x)`: Counts elements in `v` greater than or equal to `x`.
    *   `static inline int less_equal(const Vec&v,  int x)`: Counts elements in `v` less than or equal to `x`.
    *   `static inline int in_range(const Vec&v,  int x, int y)`: Counts elements in `v` within the range `[x, y]`.
    *   `static inline int equal(const Vec&v, int x)`: Counts elements in `v` equal to `x`.