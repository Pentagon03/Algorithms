# Data Structure/RangeQuery/DynamicSegGeneralized(MultiDimensional).cpp

This file contains a struct. You need to create an object of the struct to use it.

## DynamicSeg

```cpp
template<   class Range,
            class S>
struct DynamicSeg{
    // ...
};
```

*   **Description:** A struct for implementing a generalized dynamic segment tree (supports multi-dimensional ranges).
*   **Template Parameters:**
    *   `Range`: The type of the range (index).
    *   `S`: The type of the node monoid.
*   **Usage:** Create an object of the `DynamicSeg` struct and then call the member functions.

*   **Functions:**
    *   `upd(Range i, U &&unary, C &&combine)`: Updates the value at index `i` using a unary function and combines the results.
    *   `qry(Range l, Range r, U &&unary, C &&fold, V init) const`: Queries the range `[l, r]` using a unary function and folds the results with an initial value.
    *   `qry_all(U &&unary) const`: Queries the entire range using a unary function.
    *   `partition_point(G &&g, C &&fold, V init)`: Finds the partition point using a given predicate, fold function, and initial value.
