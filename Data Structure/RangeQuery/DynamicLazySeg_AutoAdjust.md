# Data Structure/RangeQuery/DynamicLazySeg_AutoAdjust.cpp

This file contains a struct. You need to create an object of the struct to use it.

## DynamicLazySeg

```cpp
struct DynamicLazySeg{
    // ...
};
```

*   **Description:** A struct for implementing a dynamic lazy segment tree with automatic memory adjustment.
*   **Usage:** Create an object of the `DynamicLazySeg` struct and then call the member functions.

*   **Functions:**
    *   `upd(Range l, Range r, F f)`: Applies the update `f` to the range `[l, r]`.
    *   `qry(Range l, Range r)`: Queries the range `[l, r]` and returns the result.
    *   `qry_all()`: Queries the entire range and returns the result.
