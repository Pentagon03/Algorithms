# Data Structure/RangeQuery/BIT.cpp

This file contains a struct. You need to create an object of the struct to use it.

## BIT

```cpp
template<typename T>
struct BIT{
    // ...
};
```

*   **Description:** A struct for implementing a Binary Indexed Tree (Fenwick Tree).
*   **Template Parameters:**
    *   `T`: The type of the elements in the BIT.
*   **Usage:** Create an object of the `BIT` struct and then call the member functions.

*   **Functions:**
    *   `upd(int p, T v)`: Updates the value at index `p` by adding `v`.
    *   `qry(int p) const`: Queries the sum of the range from 1 to `p`.
    *   `lower_bound(T x)`: Returns the minimum index `lb` such that the sum from 1 to `lb` is greater than or equal to `x`.
