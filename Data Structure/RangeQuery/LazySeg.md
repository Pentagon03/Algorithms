# Data Structure/RangeQuery/LazySeg.cpp

This file contains a struct. You need to create an object of the struct to use it.

## LazySeg

```cpp
template<   class S, S (*e)(),
            S (*op)(S, S),
            class F, F(*id)(), 
            void (*mapping)(F, S&),
            void (*composition)(F, F&)>
struct LazySeg{
    // ...
};
```

*   **Description:** A struct for implementing a lazy segment tree.
*   **Template Parameters:**
    *   `S`: The type of the node monoid.
    *   `e`: Identity element of the monoid.
    *   `op`: Monoid action.
    *   `F`: Mapping function type.
    *   `id`: Identity element of the mapping function.
    *   `mapping`: Function to apply the mapping function to a node.
    *   `composition`: Function to compose two mapping functions.
*   **Usage:** Create an object of the `LazySeg` struct and then call the member functions.

*   **Functions:**
    *   `LazySeg(int n = 0)`: Constructor with size `n`, initializes with identity element.
    *   `LazySeg(const vector<S>& v)`: Constructor with a vector of values.
    *   `upd(int l, int r, F f)`: Updates the range `[l, r]` with the mapping function `f`.
        ```cpp
        // i \in [l, r], A[i] => f(A[i])
        void upd(int l, int r, F f);
        ```
    *   `qry(int l, int r)`: Queries the range `[l, r]` and returns the result of the monoid action.
        ```cpp
        // op(A[l], ... , A[r])
        S qry(int l, int r);
        ```
    *   `qry_all()`: Queries the entire range.
